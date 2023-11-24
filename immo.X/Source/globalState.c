#include "..\Include\globalState.h"
#include "..\Include\beanTasks.h"
#include <bean.h>
#include "..\Include\ports.h"
#include "..\Include\spi.h"
#include "..\Include\initialTasks.h"
#include "..\Include\typeConvert.h"

GlobalState state;

void initGlobalState() {
  state.usbCommand = USB_NO_CMD;
  state.usbTxData[0] = 0;
  resetRecBuffer(&state.recBeanData);
  resetSendBuffer(&state.sendBeanData);
  state.prevBean = BEAN_IN;
  state.disableImmoBeanSend = 0;
  
  state.soundPlaying = 0;
  state.beeper_ctrl_out = 0;
  state.spiTask = SPI_NO_TASK;
  state.spiAddr = 0;
  state.spiSendIdx = 0;
  state.initialTasks = SPI_WRITE_RESET_REASON | PLAY_WELCOME_SOUND;
  state.spiIsStopFound = 0;
  state.lstSpiSendCmd = 0xFFFF;

  state.secTasks = 0;

  state.ms10 = 0;
  state.min = 0;
  state.hour = 0;

  state.portsState[0] = 0;
  state.portsState[1] = 0;
  state.portsState[2] = 0;
  state.portsState[3] = 0;

  state.portsTest[0] = BUTTON_TEST_STATE_MID;
  state.portsTest[1] = BUTTON_TEST_STATE_MID;
  state.portsTest[2] = BUTTON_TEST_STATE_MID;
  state.portsTest[3] = BUTTON_TEST_STATE_MID;

  state.immoState = IMMO_UNKNOWN;
  state.immoStateChangeNotified = 0;
  state.btnPressSt = 0xFFFF;
  state.shortPressProcessed = 0;
  state.longPressProcessed = 0;
  state.immoOnOffms = 0xFFFF;
  state.btnLongPressed = 0;
  state.immoOn = 0;
  state.immoInState = IMMO_IN_UNKNOWN;
  state.immoInLastCmdms = 0;
  state.immoIn5msDelaySpiCmdSend = 0;
}

void sendGlobalState() {
  if (state.usbCommand != USB_MONITOR_GLOBAL_STATE && state.usbCommand != USB_GET_GLOBAL_STATE) return;
  if (state.usbTxData[0]) return;

  if (state.usbCommand == USB_GET_GLOBAL_STATE) state.usbCommand = USB_NO_CMD;

  state.usbTxData[0] = 18;
  state.usbTxData[1] = USB_GOT_GLOBAL_STATE;
  uint32ToByteArr(&state.usbTxData[2], state.spiAddr);
  state.usbTxData[6] = state.spiTask;
  state.usbTxData[7] = state.initialTasks;
  state.usbTxData[8] = (state.portsState[BUTTON_IN_IDX]) | (state.portsState[CAPOT_IN_IDX] << 1) | (state.portsState[IMMO_SENCE_IDX] << 2) | (state.portsState[ASR12V_IN_IDX] << 3);
  state.usbTxData[9] = state.portsTest[BUTTON_IN_IDX];
  state.usbTxData[10] = state.portsTest[CAPOT_IN_IDX];
  state.usbTxData[11] = state.portsTest[IMMO_SENCE_IDX];
  state.usbTxData[12] = state.portsTest[ASR12V_IN_IDX];
  state.usbTxData[13] = state.ms10;
  state.usbTxData[14] = state.ms10 >> 8;
  state.usbTxData[15] = state.min;
  state.usbTxData[16] = state.hour;

  state.usbTxData[17] = state.immoState;
  state.usbTxData[18] = state.immoInState;
}

void globalStateTasks () {
  if (state.ms10 % 100 == 0) {
    if (!(state.secTasks & SEC_TASK_SEND_GLOBAL_STATE)) {
      sendGlobalState();
      state.secTasks |= SEC_TASK_SEND_GLOBAL_STATE;
    }
  }
  else {
    state.secTasks &= ~SEC_TASK_SEND_GLOBAL_STATE;
  }
}