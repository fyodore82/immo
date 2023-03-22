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
  state.soundPlaying = 0;
  state.spiTask = SPI_NO_TASK;
  state.spiAddr = 0;
  state.spiSendIdx = 0;
  state.initialTasks = SPI_FIND_STOP_ADDR | SPI_WRITE_RESET_REASON;
  state.sec = 0;

  state.portsState[0] = 0;
  state.portsState[1] = 1;
  state.portsState[2] = 0;
  state.portsState[3] = 0;
  
  state.portsTest[0] = BUTTON_TEST_STATE_MID;
  state.portsTest[1] = BUTTON_TEST_STATE_MID;
  state.portsTest[2] = BUTTON_TEST_STATE_MID;
  state.portsTest[3] = BUTTON_TEST_STATE_MID;
}

void sendGlobalState() {
  if (state.usbCommand != USB_MONITOR_GLOBAL_STATE && state.usbCommand != USB_GET_GLOBAL_STATE) return;
  if (state.usbTxData[0]) return;
  
  if (state.usbCommand == USB_GET_GLOBAL_STATE) state.usbCommand = USB_NO_CMD;
 
  state.usbTxData[0] = 12;
  state.usbTxData[1] = USB_GOT_GLOBAL_STATE;
  uint32ToByteArr(&state.usbTxData[2], state.spiAddr);
  state.usbTxData[6] = state.spiTask;
  state.usbTxData[7] = state.initialTasks;
  state.usbTxData[8] = (state.portsState[BUTTON_IN_IDX]) | (state.portsState[CAPOT_IN_IDX] << 1) | (state.portsState[IMMO_SENCE_IDX] << 2) | (state.portsState[ASR12V_IN_IDX] << 3);
  state.usbTxData[9] = state.portsTest[BUTTON_IN_IDX];
  state.usbTxData[10] = state.portsTest[CAPOT_IN_IDX];
  state.usbTxData[11] = state.portsTest[IMMO_SENCE_IDX];
  state.usbTxData[12] = state.portsTest[ASR12V_IN_IDX];
}