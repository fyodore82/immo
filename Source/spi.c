
#include <xc.h>
#include "..\Include\globalState.h"

void txSPI(uint32_t spi) {
  uint32_t spiP = SPI1BUF;
  IFS1bits.SPI1RXIF = 0;
  SPI1CONbits.ON = 1;
  SPI1BUF = spi;
 
}

void spiTasks() {
  if (IFS1bits.SPI1RXIF && state.usbCommand == USB_SPI_SEND_CMD) {
    uint32_t spi = SPI1BUF;
    IFS1bits.SPI1RXIF = 0;
    SPI1CONbits.ON = 0;
    state.usbTxData[0] = 5;
    state.usbTxData[1] = USB_POST_SPI_RESP;
    state.usbTxData[2] = (uint8_t) (spi >> 24);
    state.usbTxData[3] = (uint8_t) (spi >> 16);
    state.usbTxData[4] = (uint8_t) (spi >> 8);
    state.usbTxData[5] = (uint8_t) (spi);
    state.usbCommand = USB_NO_CMD;
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
