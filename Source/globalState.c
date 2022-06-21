#include "..\Include\globalState.h"

GlobalState state;

void initGlobalState () {
  state.usbCommand = USB_NO_CMD;
  state.usbTxData[0] = 0;
}