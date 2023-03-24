#include <xc.h>
#include "..\Include\StateControl.h"
#include "..\Include\ports.h"
#include "..\Include\globalState.h"
#include <bean.h>

uint8_t immoOutOkCmd[] = {0x12, 0x11, 0x10, 0x09};
uint8_t immoOutAlertCmd[] = {0x12, 0x11, 0x10, 0x09};

void processStateChange() {
  if (!IMMO_ON_OUT && !state.portsState[ASR12V_IN_IDX]) IMMO_ON_OUT = 1;
  if (IMMO_ON_OUT && state.portsState[ASR12V_IN_IDX]) IMMO_ON_OUT = 0;

  // Immo in OK state - immediately notify
  if ((state.portsState[IMMO_SENCE_IDX] || state.portsState[ASR12V_IN_IDX])
          && state.immoState != IMMO_OK) {
    initSendBeanData(&state.sendBeanData, immoOutOkCmd);
    state.immoState = IMMO_OK;
  }

  // Immo alert = immedeately notify
  if (!state.portsState[IMMO_SENCE_IDX]
          && !state.portsState[ASR12V_IN_IDX]
          && state.immoState != IMMO_ALERT) {
    initSendBeanData(&state.sendBeanData, immoOutAlertCmd);
    state.immoState = IMMO_ALERT;
  }

  // Send immoOutCmd every 4 seconds
  if (state.ms10 % 400 == 0) {
    if (!state.immoStateChangeNotified) {
      state.immoStateChangeNotified = 1;
      if (state.immoState == IMMO_OK) initSendBeanData(&state.sendBeanData, immoOutOkCmd);
      if (state.immoState == IMMO_ALERT) initSendBeanData(&state.sendBeanData, immoOutAlertCmd);
    }
  } else {
    // Prepare for next 4 seconds interval
    state.immoStateChangeNotified = 0;
  }
}
