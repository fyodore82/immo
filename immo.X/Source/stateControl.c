#include <xc.h>
#include "..\Include\StateControl.h"
#include "..\Include\ports.h"
#include "..\Include\globalState.h"
#include "..\Include\typeConvert.h"
#include <bean.h>
#include "..\Include\spi.h"
#include "..\Include\sounds.h"

uint8_t immoOutOkAsrCmd[] = {0x13, 0x33, 0x44,0x11, 0x62};
uint8_t immoOutOkImmoCmd[] = {0x13, 0x33, 0x44, 0x12, 0x57};
uint8_t immoOutAlertCmd[] = {0x13, 0x33, 0x44, 0x21, 0x01};

uint8_t immoInOkCmd[] = {0x13, 0x44, 0x33, 0x11, 0x94};
uint8_t immoInAlertCmd[] = {0x13, 0x44, 0x33, 0x22, 0xC4};

void processStateChange() {
  // ASR12V - ON when normal IG is ON
  // ASR12V is OFF when ASR is controlling IG
  if (!state.btnLongPressed) {
    // Code below relates only to normal immo operation,
    // i.e. when button is not pressed
    if (!state.immoOn && state.portsState[ASR12V_IN_IDX]) {
      state.immoOnOffms = state.ms10;
      state.immoOn = 1;
      IMMO_ON_OUT = 1;
      state.logType = LOG_ENTRY_STATE_CHANGE;
    }
    // If immo is turned OFF, it can happen only by ASR12V is 1
    // Immedeately process change, as we don't need to wait for IMMO_SENCE
    if (state.immoOn && !state.portsState[ASR12V_IN_IDX]) {
      state.immoOn = 0;
      IMMO_ON_OUT = 0;
      state.logType = LOG_ENTRY_STATE_CHANGE;
    }
  }

  uint16_t immoStChangeDelay = calcDelay(state.immoOnOffms);

  // At least 100 ms should pass after IMMO state chenge to chenge state
  // Or we have already processed IMMO_ON_OUT change
  if (state.immoOnOffms == 0xFFFF || immoStChangeDelay >= 10) {
    state.immoOnOffms = 0xFFFF;

    // Immo in OK state - immediately notify
    if (!state.portsState[ASR12V_IN_IDX]) {
      if (state.immoState != IMMO_OK_ASR12V) {
//        if (!state.disableImmoBeanSend) {
//          initSendBeanData(&state.sendBeanData, immoOutOkAsrCmd);
//        }
        state.immoState = IMMO_OK_ASR12V;
        state.logType = LOG_ENTRY_STATE_CHANGE;
      }
    }
    else if (state.portsState[IMMO_SENCE_IDX] && state.immoState != IMMO_OK_IMMO) {
//      if (!state.disableImmoBeanSend) {
//        initSendBeanData(&state.sendBeanData, immoOutOkImmoCmd);
//      }
      state.immoState = IMMO_OK_IMMO;
      state.logType = LOG_ENTRY_STATE_CHANGE;
    }

    // Immo alert = immedeately notify
    if (!state.portsState[IMMO_SENCE_IDX]
        && state.portsState[ASR12V_IN_IDX]
        && state.immoState != IMMO_ALERT) {
//      if (!state.disableImmoBeanSend) {
//        initSendBeanData(&state.sendBeanData, immoOutAlertCmd);
//      }
      state.immoState = IMMO_ALERT;
      state.logType = LOG_ENTRY_STATE_CHANGE;
    }

    // Send immoOutCmd every 4 seconds
    if (state.ms10 % 400 == 0) {
      if (!state.immoStateChangeNotified && !state.disableImmoBeanSend) {
        state.immoStateChangeNotified = 1;
//        if (state.immoState == IMMO_OK_ASR12V) initSendBeanData(&state.sendBeanData, immoOutOkAsrCmd);
//        if (state.immoState == IMMO_OK_IMMO) initSendBeanData(&state.sendBeanData, immoOutOkImmoCmd);
//        if (state.immoState == IMMO_ALERT) initSendBeanData(&state.sendBeanData, immoOutAlertCmd);
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
      uint16_t btnPressDel = calcDelay(state.btnPressSt);
      // Button has been pressed for more than 1 sec
      if (btnPressDel >= 100) {
        state.btnPressSt = 0xFFFF;
        state.btnLongPressed = !state.btnLongPressed;
        // state.immoState = state.immoState == IMMO_BTN_PRESSED ? IMMO_UNKNOWN : IMMO_BTN_PRESSED;
        state.longPressProcessed = 1;
        state.logType = LOG_ENTRY_STATE_CHANGE;
        if (state.btnLongPressed) {
          playSound(nokiaRingtoneSound);
        }
      }
    }
  }

  if (state.portsState[BUTTON_IN_IDX] && !state.shortPressProcessed && state.btnLongPressed) {
    state.shortPressProcessed = 1;
    state.immoOn = !state.immoOn;
    IMMO_ON_OUT = state.immoOn;
    state.logType = LOG_ENTRY_STATE_CHANGE;
  }

  if (!state.portsState[BUTTON_IN_IDX]) {
    state.btnPressSt = 0xFFFF;
    state.longPressProcessed = 0;
    state.shortPressProcessed = 0;
  }
}
