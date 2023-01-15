#include <xc.h>
#include "..\Include\ports.h"
#include <string.h>
#include "..\Include\globalState.h"
#include "..\Include\beanTasks.h"
#include "..\Include\typeConvert.h"

void getPorts() {
  if (!state.usbTxData[0]) {
    state.usbTxData[0] = 9;
    state.usbTxData[1] = USB_POST_PORTS_STATE;
    uint32_t port = PORTA;
    uint32ToByteArr(&state.usbTxData[2], port);
    port = PORTB;
    uint32ToByteArr(&state.usbTxData[6], port);
  }
}

void setPorts(unsigned char newState, unsigned char* ports) {
    if (ports[3] & 0b10000) IMMO_ON_OUT = !!newState;
    if (ports[6] & 0b10000000) BEEPER_CTRL_OUT = !!newState;
    if (ports[6] & 0b100000) BEAN_OUT = !!newState;
}

void __attribute__((nomips16)) __attribute__((interrupt(), vector(_CHANGE_NOTICE_VECTOR))) _changeNoticeVector(void) {
  if (IFS1bits.CNBIF || IFS1bits.CNAIF) {
    IFS1bits.CNBIF = 0;
    IFS1bits.CNAIF = 0;
    if (state.usbCommand == USB_MONITOR_PORTS_STATE) getPorts();
    else {
      if (BEAN_IN_CNSTAT) processBeanInPortChange();
    }
  }
  CNSTATB = 0;
  CNSTATA = 0;
}
