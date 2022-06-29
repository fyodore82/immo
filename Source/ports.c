#include <xc.h>
#include "..\Include\ports.h"
#include <string.h>
#include "..\Include\globalState.h"
#include "..\Include\beanTasks.h"

void getPorts() {
  if (!state.usbTxData[0]) {
    state.usbTxData[0] = 9;
    state.usbTxData[1] = USB_POST_PORTS_STATE;
    uint32_t port = PORTA;
    state.usbTxData[2] = (uint8_t) (port >> 24);
    state.usbTxData[3] = (uint8_t) (port >> 16);
    state.usbTxData[4] = (uint8_t) (port >> 8);
    state.usbTxData[5] = (uint8_t) port;
    port = PORTB;
    state.usbTxData[6] = (uint8_t) (port >> 24);
    state.usbTxData[7] = (uint8_t) (port >> 16);
    state.usbTxData[8] = (uint8_t) (port >> 8);
    state.usbTxData[9] = (uint8_t) port;
  }
}

void __attribute__((nomips16)) __attribute__((interrupt(), vector(_CHANGE_NOTICE_VECTOR))) _changeNoticeVector(void) {
  if (IFS1bits.CNBIF) {
    IFS1bits.CNBIF = 0;
    if (state.usbCommand == USB_BEAN_DEBUG) getPorts();
    else {
      if (BEAN_IN_CNSTAT) processBeanInPortChange();
    }
    CNSTATB = 0;
  }
}
