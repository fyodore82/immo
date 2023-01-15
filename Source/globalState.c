#include "..\Include\globalState.h"
#include "..\Include\beanTasks.h"
#include <bean.h>
#include "..\Include\ports.h"

GlobalState state;

void initGlobalState () {
  state.usbCommand = USB_NO_CMD;
  state.usbTxData[0] = 0;
  resetRecBuffer(&state.recBeanData);
  resetSendBuffer(&state.sendBeanData);
  state.prevBean = BEAN_IN;
//  
//  state.readPos = 0;
//  state.writePos = 0;
}