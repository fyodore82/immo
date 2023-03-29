#include <xc.h>
#include "..\Include\StateControl.h"
#include "..\Include\ports.h"
#include "..\Include\globalState.h"
#include <bean.h>
#include "..\Include\spi.h"

uint8_t immoOutOkAsrCmd[] = {0x12, 0x11, 0x10, 0x09, 0x08};
uint8_t immoOutOkImmoCmd[] = {0x12, 0x11, 0x11, 0x09, 0x08};
uint8_t immoOutAlertCmd[] = {0x12, 0x11, 0x12, 0x09, 0x08};

void processStateChange() {
  if (!state.btnLongPressed) {
    // Code below relates only to normal immo operation,
    // i.e. when button is not pressed
    if (!IMMO_ON_OUT && !state.portsState[ASR12V_IN_IDX]) {
      state.immoOnOffms = state.ms10;
      IMMO_ON_OUT = 1;
      writeLog(LOG_ENTRY_STATE_CHANGE);
    }
    // If immo is turned OFF, it can happen only by ASR12V is 1
    // Immedeately process change, as we don't need to wait for IMMO_SENCE
    if (IMMO_ON_OUT && state.portsState[ASR12V_IN_IDX]) {
      IMMO_ON_OUT = 0;
      writeLog(LOG_ENTRY_STATE_CHANGE);
    }
  }

  uint16_t immoStChangeDelay = state.immoOnOffms <= state.ms10
    ? state.ms10 - state.immoOnOffms
    : 6000 - state.immoOnOffms + state.ms10;

  // At least 100 ms should pass after IMMO state chenge to chenge state
  // Or we have already processed IMMO_ON_OUT change
  if (state.immoOnOffms == 0xFFFF || immoStChangeDelay >= 10) {
    state.immoOnOffms = 0xFFFF;

    // Immo in OK state - immediately notify
    if (state.portsState[ASR12V_IN_IDX]) {
      if (state.immoState != IMMO_OK_ASR12V) {
        initSendBeanData(&state.sendBeanData, immoOutOkAsrCmd);
        state.immoState = IMMO_OK_ASR12V;
        writeLog(LOG_ENTRY_STATE_CHANGE);
      }
    }
    else if (state.portsState[IMMO_SENCE_IDX] && state.immoState != IMMO_OK_IMMO) {
      initSendBeanData(&state.sendBeanData, immoOutOkImmoCmd);
      state.immoState = IMMO_OK_IMMO;
      writeLog(LOG_ENTRY_STATE_CHANGE);
    }

    // Immo alert = immedeately notify
    if (!state.portsState[IMMO_SENCE_IDX]
        && !state.portsState[ASR12V_IN_IDX]
        && state.immoState != IMMO_ALERT) {
      initSendBeanData(&state.sendBeanData, immoOutAlertCmd);
      state.immoState = IMMO_ALERT;
      writeLog(LOG_ENTRY_STATE_CHANGE);
    }

    // Send immoOutCmd every 4 seconds
    if (state.ms10 % 400 == 0) {
      if (!state.immoStateChangeNotified) {
        state.immoStateChangeNotified = 1;
        if (state.immoState == IMMO_OK_ASR12V) initSendBeanData(&state.sendBeanData, immoOutOkAsrCmd);
        if (state.immoState == IMMO_OK_IMMO) initSendBeanData(&state.sendBeanData, immoOutOkImmoCmd);
        if (state.immoState == IMMO_ALERT) initSendBeanData(&state.sendBeanData, immoOutAlertCmd);
      }
    } else {
      // Prepare for next 4 seconds interval
      state.immoStateChangeNotified = 0;
    }
  }

  // Check if this is btn long press
  if (state.portsState[BUTTON_IN_IDX] && !state.longPressProcessed) {
    if (state.btnPressSt == 0xFFFF) state.btnPressSt = state.ms10;
    else {
      uint16_t btnPressDel = state.btnPressSt <= state.ms10
        ? state.ms10 - state.btnPressSt
        : 6000 - state.btnPressSt + state.ms10;
      // Button has been pressed for more than 1 sec
      if (btnPressDel >= 100) {
        state.btnPressSt = 0xFFFF;
        state.btnLongPressed = !state.btnLongPressed;
        // state.immoState = state.immoState == IMMO_BTN_PRESSED ? IMMO_UNKNOWN : IMMO_BTN_PRESSED;
        state.longPressProcessed = 1;
        writeLog(LOG_ENTRY_STATE_CHANGE);
      }
    }
  }

  if (state.portsState[BUTTON_IN_IDX] && !state.shortPressProcessed && state.btnLongPressed) {
    state.shortPressProcessed = 1;
    IMMO_ON_OUT = !IMMO_ON_OUT;
    writeLog(LOG_ENTRY_STATE_CHANGE);
  }

  if (!state.portsState[BUTTON_IN_IDX]) {
    state.btnPressSt = 0xFFFF;
    state.longPressProcessed = 0;
    state.shortPressProcessed = 0;
  }
}
