
#include <xc.h>
#include "..\Include\globalState.h"
#include "..\Include\typeConvert.h"
#include "..\Include\spi.h"

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
      uint32_t data = SPI1BUF;  // This is bus state when address has been sent
      data = SPI1BUF; // Second read yeild data
      // 0xFFFFFFFF means that bytes are erased
      if (data == 0xFFFFFFFF) {
        state.spiTask = SPI_NO_TASK;
      } else {
        state.spiAddr += 4;
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
      txSPI(state.spiSend[state.spiSendIdx], state.spiSend[state.spiSendIdx + 1]);
      state.spiSendIdx += 2;
      if (state.spiSendIdx >= SPI_SEND_BUFF || state.spiSend[state.spiSendIdx] == 0) {
        state.spiTask = SPI_NO_TASK;
        state.spiSendIdx = 0;
        for (uint8_t i = 0; i < SPI_SEND_BUFF; i++) {
          state.spiSend[i] = 0;
        }
      }
      break;
  }
}

void writeLog(uint32_t data) {
  if (state.spiTask != SPI_NO_TASK) return;
  state.spiSend[0] = 0x06000000;  // Write enable
  state.spiSend[1] = 0;
  state.spiSend[2] = 0x02000000 | state.spiAddr;
  state.spiSend[3] = (state.hour << 24) | (state.min << 16) | state.ms10;
  state.spiAddr += 4;
  state.spiSend[4] = 0x06000000;  // Write enable
  state.spiSend[5] = 0;
  state.spiSend[6] = 0x02000000 | state.spiAddr;
  state.spiSend[7] = data; // Write data
  state.spiAddr += 4;
  if (state.spiAddr >= SPI_MAX_ADDR) state.spiAddr = 0; // Roll over to the start
  if (!(state.spiAddr & SPI_SMALL_SECTOR)) {
    state.spiSend[8] = 0xd7000000 | state.spiAddr; // Erase next sector
    state.spiSend[9] = 0;
  }
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
