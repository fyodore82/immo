#include <xc.h>
#include "..\Include\ports.h"
#include <string.h>
#include "..\Include\globalState.h"
#include "..\Include\beanTasks.h"

void getPorts(unsigned char *out) {
  uint32_t port = PORTA;
  out[0] = (uint8_t) (port >> 24);
  out[1] = (uint8_t) (port >> 16);
  out[2] = (uint8_t) (port >> 8);
  out[3] = (uint8_t) port;
  port = PORTB;
  out[4] = (uint8_t) (port >> 24);
  out[5] = (uint8_t) (port >> 16);
  out[6] = (uint8_t) (port >> 8);
  out[7] = (uint8_t) port;
}

void __attribute__((nomips16)) __attribute__((interrupt(), vector(_CHANGE_NOTICE_VECTOR))) _changeNoticeVector(void) {
  if (IFS1bits.CNBIF) {
    IFS1bits.CNBIF = 0;
    if(state.usbCommand == USB_BEAN_DEBUG) {
      state.usbTxData[0] = 9;
      state.usbTxData[1] = USB_POST_PORTS_STATE;
      getPorts(&state.usbTxData[2]);
    }
    if (BEAN_IN_CNSTAT) processBeanInPortChange();
    CNSTATB = 0;
  }
}
