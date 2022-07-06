
#include <xc.h>
#include "..\Include\globalState.h"
#include "..\Include\typeConvert.h"

void txSPI() {
  // Read all enhanced FIFO buffer
  uint32_t spiP = SPI1BUF;
  spiP = SPI1BUF;
  spiP = SPI1BUF;
  spiP = SPI1BUF;
  state.spiRecIdx = 0;
  IFS1bits.SPI1RXIF = 0;
//  SPI1CONbits.ON = 1;
  SPI1BUF = state.spiCmd[0];
  SPI1BUF = state.spiCmd[1];
}

void spiTasks() {
  if (state.usbCommand != USB_SPI_SEND_CMD) return;
  if (IFS1bits.SPI1RXIF) {
    state.spiReceive[state.spiRecIdx++] = SPI1BUF;
    IFS1bits.SPI1RXIF = 0;
  }
  if (state.spiRecIdx == 2) {
//    SPI1CONbits.ON = 0;
    if (state.usbTxData[0]) return;
    state.usbCommand = USB_NO_CMD;
    state.usbTxData[0] = 17;
    state.usbTxData[1] = USB_POST_SPI_RESP;
    uint32ToByteArr(&state.usbTxData[2], state.spiReceive[0]);
    uint32ToByteArr(&state.usbTxData[6], state.spiReceive[1]);
    uint32ToByteArr(&state.usbTxData[10], state.spiCmd[0]);
    uint32ToByteArr(&state.usbTxData[14], state.spiCmd[1]);
//    state.usbTxData[2] = (uint8_t) (state.spiCmd >> 24);
//    state.usbTxData[3] = (uint8_t) (state.spiCmd >> 16);
//    state.usbTxData[4] = (uint8_t) (state.spiCmd >> 8);
//    state.usbTxData[5] = (uint8_t) (state.spiCmd);
//    state.usbTxData[6] = (uint8_t) (state.spiReceive[0] >> 24);
//    state.usbTxData[7] = (uint8_t) (state.spiReceive[0] >> 16);
//    state.usbTxData[8] = (uint8_t) (state.spiReceive[0] >> 8);
//    state.usbTxData[9] = (uint8_t) (state.spiReceive[0]);
//    state.usbTxData[10] = (uint8_t) (state.spiReceive[1] >> 24);
//    state.usbTxData[11] = (uint8_t) (state.spiReceive[1] >> 16);
//    state.usbTxData[12] = (uint8_t) (state.spiReceive[1] >> 8);
//    state.usbTxData[13] = (uint8_t) (state.spiReceive[1]);

  }
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
