
#include <xc.h>
#include "..\Include\globalState.h"
#include "..\Include\typeConvert.h"
#include "..\Include\spi.h"
#include "..\Include\ports.h"

void txSPI(uint32_t addr, uint32_t data) {
  // Read all enhanced FIFO buffer
  uint32_t spiP = SPI1BUF;
  spiP = SPI1BUF;
  spiP = SPI1BUF;
  spiP = SPI1BUF;
  state.spiRecIdx = 0;
  IFS1bits.SPI1RXIF = 0;
  //  SPI1CONbits.ON = 1;
  SPI1BUF = addr; // Addr
  SPI1BUF = data; // Data
}

void spiTasks() {
  uint32_t data; // Is only used in SPI_FIND_STOP
  uint16_t delay = state.lstSpiSendCmd <= state.ms10
    ? state.ms10 - state.lstSpiSendCmd
    : 6000 - state.lstSpiSendCmd + state.ms10;

  switch (state.spiTask) {
    case SPI_EXEC_USB_CMD:
      if (IFS1bits.SPI1RXIF) {
        state.spiReceive[state.spiRecIdx++] = SPI1BUF;
        IFS1bits.SPI1RXIF = 0;
      }
      if (state.spiRecIdx == 2) {
        if (state.usbTxData[0]) return;
        state.usbCommand = USB_NO_CMD;
        state.usbTxData[0] = 9;
        state.usbTxData[1] = USB_POST_SPI_RESP;
        uint32ToByteArr(&state.usbTxData[2], state.spiReceive[0]);
        uint32ToByteArr(&state.usbTxData[6], state.spiReceive[1]);
        state.spiTask = SPI_NO_TASK;
      }
      break;
    case SPI_FIND_STOP:
      if (!IFS1bits.SPI1RXIF) break;
      IFS1bits.SPI1RXIF = 0;
      data = SPI1BUF;  // This is bus state when address has been sent
      data = SPI1BUF; // Second read yeild data
      // 0xFFFFFFFF means that bytes are erased
      if (data == 0xFFFFFFFF) {
        state.spiTask = SPI_NO_TASK;
      } else {
        // Move by 8 bytes. 4 bytes - time, 4 bytes - data
        state.spiAddr += 8;
        if (state.spiAddr >= SPI_MAX_ADDR) {
          state.spiAddr = 0;
          state.spiTask = SPI_NO_TASK;
        } else {
          txSPI(0x03000000 | state.spiAddr, 0);
        }
      }
      break;
    case SPI_SEND_DATA:
      if (!IFS1bits.SPI1TXIF) break;
      IFS1bits.SPI1RXIF = 0;
      // Minimum 20ms has not been elapsed between concurrent SPI commands
      if (state.lstSpiSendCmd != 0xFFFF && delay < 2) break;
        // On last iteration check if address poining on the nex sector and erase it
        if (state.spiSendIdx >= SPI_SEND_BUFF) {
        // Small sector erase should occur only on first call to tsSpi
          if (!(state.spiAddr & SPI_SMALL_SECTOR)) {
            txSPI(0xd7000000, 0);
          }
          state.spiTask = SPI_NO_TASK;
          state.lstSpiSendCmd = 0xFFFF;
          state.spiSendIdx = 0;
          break;
        }

      state.lstSpiSendCmd = state.ms10;

      txSPI(state.spiSend[state.spiSendIdx], state.spiSend[state.spiSendIdx + 1]);
      state.spiSendIdx += 2;
      break;
  }
}

void writeLog() {
  if (state.spiTask != SPI_NO_TASK || state.logType == DONT_LOG) return;
  state.spiSend[0] = 0x06000000;  // Write enable
  state.spiSend[1] = 0;
  state.spiSend[2] = 0x02000000 | state.spiAddr;
  state.spiSend[3] = (state.hour << 24) | (state.min << 16) | state.ms10;
  state.spiAddr += 4;
  state.spiSend[4] = 0x06000000;  // Write enable
  state.spiSend[5] = 0;
  state.spiSend[6] = 0x02000000 | state.spiAddr;
  state.spiSend[7] = ((uint8_t)state.logType << 24)
    | (IMMO_ON_OUT << 4)
    | (state.portsState[BUTTON_IN_IDX])
    | (state.portsState[CAPOT_IN_IDX] << 1)
    | (state.portsState[IMMO_SENCE_IDX] << 2)
    | (state.portsState[ASR12V_IN_IDX] << 3);
  if (state.logType == LOG_ENTRY_STATE_CHANGE) {
    state.spiSend[7] |= (state.immoState << 16) | (state.btnLongPressed << 8); // Write data
  } else {
    state.spiSend[7] |= ((uint16_t)RCON << 8);
  }
  
  state.spiAddr += 4;
  if (state.spiAddr >= SPI_MAX_ADDR) state.spiAddr = 0; // Roll over to the start
  state.logType = DONT_LOG;
  state.spiTask = SPI_SEND_DATA;
  state.spiSendIdx = 0;
}

  //void __attribute__((nomips16)) __attribute__((interrupt(), vector(_SPI_1_VECTOR))) _spiVector(void) {
  //  if (IFS1bits.SPI1RXIF) {
  //    uint32_t spi = SPI1BUF;
  //    IFS1bits.SPI1RXIF = 0;
  //    state.usbTxData[0] = 5;
  //    state.usbTxData[1] = USB_POST_SPI_RESP;
  //    state.usbTxData[2] = (uint8_t) (spi >> 24);
  //    state.usbTxData[3] = (uint8_t) (spi >> 16);
  //    state.usbTxData[4] = (uint8_t) (spi >> 8);
  //    state.usbTxData[5] = (uint8_t) (spi);
  //  }
  //}
