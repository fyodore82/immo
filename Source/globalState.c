#include "..\Include\globalState.h"
#include "..\Include\beanTasks.h"
#include <bean.h>

GlobalState state;

void initGlobalState () {
  state.usbCommand = USB_NO_CMD;
  state.usbTxData[0] = 0;
  resetRecBuffer(&state.recBeanData);
  resetSendBuffer(&state.sendBeanData);
  state.t3cnt = T3_CNT;
}