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
    if (ports[6] & 0b10) PORTBbits.RB9 = !!newState;  // For testing only
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

void __attribute__((nomips16)) __attribute__((interrupt(), vector(_TIMER_5_VECTOR))) _timer5Vector(void) {
  IFS0bits.T5IF = 0;
  if (state.buttonInTest < BUTTON_TEST_STATE_ONE && BUTTON_IN) state.buttonInTest++;
  if (state.buttonInTest > BUTTON_TEST_STATE_ZERO && !BUTTON_IN) state.buttonInTest--;

  if (state.capotInTest < BUTTON_TEST_STATE_ONE && CAPOT_IN) state.capotInTest++;
  if (state.capotInTest > BUTTON_TEST_STATE_ZERO && !CAPOT_IN) state.capotInTest--;

  if (state.immoSenceInTest < BUTTON_TEST_STATE_ONE && IMMO_SENCE_IN) state.immoSenceInTest++;
  if (state.immoSenceInTest > BUTTON_TEST_STATE_ZERO && !IMMO_SENCE_IN) state.immoSenceInTest--;

  if (state.asr12vInTest < BUTTON_TEST_STATE_ONE && ASR12V_IN) state.asr12vInTest++;
  if (state.asr12vInTest > BUTTON_TEST_STATE_ZERO && !ASR12V_IN) state.asr12vInTest--;
}
