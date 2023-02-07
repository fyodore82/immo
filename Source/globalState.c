#include "..\Include\globalState.h"
#include "..\Include\beanTasks.h"
#include <bean.h>
#include "..\Include\ports.h"
#include "..\Include\spi.h"
#include "..\Include\initialTasks.h"

GlobalState state;

void initGlobalState () {
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
 
  state.buttonIn = 0;
  state.capotIn = 0;
  state.immoSenceIn = 0;
  state.asr12vIn = 0;
  state.buttonInTest = BUTTON_TEST_STATE_MID;
  state.capotInTest = BUTTON_TEST_STATE_MID;
  state.immoSenceInTest = BUTTON_TEST_STATE_MID;
  state.asr12vInTest = BUTTON_TEST_STATE_MID;
}