#include "..\Include\beanTasks.h"
#include "..\Include\globalState.h"
#include <xc.h>

void beanTasks () {
  if (state.usbCommand == USB_BEAN_DEBUG) {
    if (state.usbSubCommand == BEAN_DEBUG_SET_1) BEAN_OUT = 1;
    if (state.usbSubCommand == BEAN_DEBUG_SET_0) BEAN_OUT = 0;
    if (state.usbSubCommand == BEAN_DEBUG_SET_0 || state.usbSubCommand == BEAN_DEBUG_SET_1) {
    
      state.usbTxData[0] = 10;
      state.usbTxData[1] = USB_BEAN_DEBUG;
      uint32_t port = PORTA;
      state.usbTxData[2] = (uint8_t)(port>>24);
      state.usbTxData[3] = (uint8_t)(port>>16);
      state.usbTxData[4] = (uint8_t)(port>>8);
      state.usbTxData[5] = (uint8_t)port;
      port = PORTB;
      state.usbTxData[6] = (uint8_t)(port>>24);
      state.usbTxData[7] = (uint8_t)(port>>16);
      state.usbTxData[8] = (uint8_t)(port>>8);
      state.usbTxData[9] = (uint8_t)port;
      state.usbTxData[10] = 0xFF;
    }
    state.usbSubCommand == USB_NO_SUBCMD;
    state.usbCommand = USB_NO_CMD;
  }
}

void __attribute__((nomips16)) __attribute__((interrupt(),vector(_CHANGE_NOTICE_VECTOR))) _changeNoticeVector( void ) {
  //if (BEAN_IN_CNSTAT) {
//    if (state.usbCommand == USB_BEAN_DEBUG) {
      state.usbTxData[0] = 0x2;
      state.usbTxData[1] = 0xFF;
      state.usbTxData[2] = 0X0F;
//    }
//  }
}
