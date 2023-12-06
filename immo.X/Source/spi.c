
#include <xc.h>
#include "..\Include\globalState.h"
#include "..\Include\typeConvert.h"
#include "..\Include\spi.h"
#include "..\Include\ports.h"
#include <string.h>

static unsigned char sendIdxTop;
static unsigned char sendIdxBottom;
static uint32_t spiSend[SPI_SEND_BUFF];    // 0 - addr, 1 - data, 2 - addr, 1 - data

static unsigned char spiLogTop;
static unsigned char spiLogBottom;
static SPILogEntryType spiLogArr[10];

static uint32_t usbAddr;
static uint32_t usbData;

static unsigned char isUsbTask;
static uint32_t spiAddr = SPI_INITIAL_ADDR;   // Current SPI address to write log to

static unsigned char spiIsStopFound;   // Is 1 when stop is found. This is very first task to do

uint32_t getSpiAddr() {
  return spiAddr;
}
unsigned char getSpiState() {
  return spiIsStopFound;   // Is 1 when stop is found. This is very first task to do
}

void writeLog();

void txSPI(uint32_t addr, uint32_t data) {
  // Read all enhanced FIFO buffer
  uint32_t spiP = SPI1BUF;
  spiP = SPI1BUF;
  spiP = SPI1BUF;
  spiP = SPI1BUF;
//  spiRecIdx = 0;
//  memset(spiReceive, 4 * 4, 0);
  // IFS1bits.SPI1RXIF = 0;
  SPI1BUF = addr; // Addr
  SPI1BUF = data; // Data
}

void sendToSpi(uint32_t addr, uint32_t data) {
  if (sendIdxBottom >= SPI_SEND_BUFF) return;

  spiSend[sendIdxBottom] = addr;
  spiSend[sendIdxBottom + 1] = data;
  sendIdxBottom += 2;
}

void processSpiSend() {
  if (!spiIsStopFound || isUsbTask) return;

  static uint16_t lstSpiSendCmd = 0xFFFF; // ms, when last SPI write cmd has been sent
                                          // Is used to introduce delay between concurrent SPI writes

  if (sendIdxTop == sendIdxBottom) {
    if (sendIdxBottom != 0) {
      sendIdxTop = 0;
      sendIdxBottom = 0;
    }
    lstSpiSendCmd = 0xFFFF;
    return;
  }

  if (!IFS1bits.SPI1RXIF) return;

  uint16_t delay = calcDelay(lstSpiSendCmd);
  // Minimum 20ms has not been elapsed between concurrent SPI commands
  if (lstSpiSendCmd != 0xFFFF && delay < 2) return;

  txSPI(spiSend[sendIdxTop], spiSend[sendIdxTop + 1]);
  sendIdxTop += 2;
  lstSpiSendCmd = state.ms10;
}

void checkForSmallSectorErase() {
  if ((spiAddr & SPI_SMALL_SECTOR) == SPI_SMALL_SECTOR) {
    sendToSpi(0x06000000, 0);  // Write enable
    sendToSpi(0xd7000000 | spiAddr, 0);
  }
}

void findStop() {
  if (spiIsStopFound || state.ms10 < 20) return;

  static unsigned char recIdx;

  if (spiAddr == SPI_INITIAL_ADDR) {
    recIdx = 0;
    txSPI(0x03000000 | spiAddr, 0);
    spiAddr += 8;
    return;
  }

  if (!IFS1bits.SPI1RXIF) return;

  // Read buffer twice as second word is data
  uint32_t recData = SPI1BUF;
  recIdx++;
  if (recIdx < 2) return;

  // 0xFFFFFFFF means that bytes are erased
  if (recData == 0xFFFFFFFF) {
    spiAddr -= 8;
    spiIsStopFound = 1;
    
  } else {
    if (spiAddr >= SPI_MAX_ADDR) {
      spiAddr = SPI_INITIAL_ADDR;
      checkForSmallSectorErase();
      spiIsStopFound = 1;
    }
    else {
      recIdx = 0;
      
      txSPI(0x03000000 | spiAddr, 0);
      spiAddr += 8;
    }
  }
}

void setUsbAddrData(uint32_t addr, uint32_t data) {
  usbAddr = addr;
  usbData = data;
}

void logSpi(SPILogEntryType logType) {
  if (spiLogBottom >= 10) return;

  spiLogArr[spiLogBottom] = logType;
  spiLogBottom++;
}

void sendSpiLog() {
  if (!spiIsStopFound || isUsbTask) return;

  if (spiLogBottom == spiLogTop) {
    if (spiLogBottom != 0) {
      spiLogBottom = 0;
      spiLogTop = 0;
    }
    return;
  }

  SPILogEntryType logType = spiLogArr[spiLogTop];
  spiLogTop++;

  sendToSpi(0x06000000, 0);  // Write enable
  sendToSpi(0x02000000 | spiAddr, (state.hour << 24) | (state.min << 16) | state.ms10);
  spiAddr += 4;
  if (spiAddr >= SPI_MAX_ADDR) spiAddr = 0; // Roll over to the start
  checkForSmallSectorErase();

  sendToSpi(0x06000000, 0);  // Write enable

  uint32_t data = ((uint8_t)logType << 24)
      | (state.immoOn << 4)
      | (state.portsState[BUTTON_IN_IDX])
      | (state.portsState[CAPOT_IN_IDX] << 1)
      | (state.portsState[IMMO_SENCE_IDX] << 2)
      | (state.portsState[ASR12V_IN_IDX] << 3);
  switch (logType) {
    case LOG_ENTRY_STATE_CHANGE:
      data |= (state.immoInState << 20) | (state.immoState << 16) | (state.btnLongPressed << 8); // Write data
      break;
    case LOG_ENTRY_IMMO_IN_5S_DELAY:
      state.immoIn5msDelaySpiCmdSend = 1;
      data |= ((uint16_t)state.immoInLastCmdms << 8);
      break;
    case LOG_ENTRY_RESET:
      data |= ((uint16_t)RCON << 8);
      break;
  }

  sendToSpi(0x02000000 | spiAddr, data);

  spiAddr += 4;
  if (spiAddr >= SPI_MAX_ADDR) spiAddr = 0; // Roll over to the start
  checkForSmallSectorErase();
}

// USB tasks processed irrespective to other routines
void spiUsbTasks() {
  if (state.usbCommand == USB_SPI_SEND_CMD || state.usbCommand == USB_SPI_GET_REGS) {
    static uint32_t spiRec[2];
    static unsigned char recIdx;

    if (!isUsbTask) {
      if (state.usbCommand == USB_SPI_SEND_CMD) {
        txSPI(usbAddr, usbData);
      }
      else {
        txSPI(0x05000000, 0);
      }
      isUsbTask = 1;
      recIdx = 0;
      spiRec[0] = 0;
      spiRec[1] = 0;
      return;
    }

    if (!IFS1bits.SPI1RXIF) return;

    spiRec[recIdx++] = SPI1BUF;

    if (recIdx == 2) {
      if (state.usbTxData[0]) return;
      state.usbTxData[0] = 9;
      state.usbTxData[1] = state.usbCommand == USB_SPI_SEND_CMD
        ? USB_POST_SPI_RESP
        : USB_POST_SPI_REGS;
      uint32ToByteArr(&state.usbTxData[2], spiRec[0]);
      uint32ToByteArr(&state.usbTxData[6], spiRec[1]);
      isUsbTask = 0;
      state.usbCommand = USB_NO_CMD;
    }
  }
}
