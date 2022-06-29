#include "..\Include\beanTasks.h"
#include "..\Include\globalState.h"
#include <xc.h>
#include "..\Include\ports.h"
#include <string.h>

// Private to this file
void sendToUSBReceivedBeanCmd() {
  // Do not check in recBufferFull as it may be error during transfer
  if (!state.usbTxData[0]) {
    unsigned char l = 17; // DATA 13 + ML + CRC + EOM + RSP
    state.usbTxData[0] = l + 2;
    state.usbTxData[1] = USB_GOT_BEAN_CMD;
    state.usbTxData[2] = state.t3cnt;
    memcpy(&state.usbTxData[3], state.recBeanData.buffer, l);
    state.recBeanData.recBufferFull = 0;
  }
}

void beanTasks() {
  switch (state.usbCommand) {
    case USB_BEAN_DEBUG:
    {
      if (state.usbSubCommand == BEAN_DEBUG_SET_1) BEAN_OUT = 1;
      if (state.usbSubCommand == BEAN_DEBUG_SET_0) BEAN_OUT = 0;
      // Pots will be chached in ports interrupt

      state.usbSubCommand = USB_NO_SUBCMD;
      break;
    }
    case USB_LISTERN_BEAN:
      if (state.recBeanData.recBufferFull) sendToUSBReceivedBeanCmd();
      break;

    case USB_SEND_BEAN_CMD:
    {
//      if (isTransferInProgress(&state.sendBeanData)) {
//        if (state.sendBeanData.cnt == 0) ;
//      } else {
      // Check if transfer is in progress as there may be errors during transfer
      // and we still have to send reponse back
      if (!isTransferInProgress(&state.sendBeanData)) {
      // if (state.recBeanData.recBufferFull) {
        state.usbCommand = USB_NO_CMD;
//        BEAN_OUT = 0;
//        T2CONbits.ON = 0;
        sendToUSBReceivedBeanCmd();
//
//        state.usbTxData[l + 1] = 0xFF;
//        state.usbTxData[l + 2] = USB_SEND_BEAN_CMD;
//        state.usbTxData[l + 3] = state.recBeanData.recBeanState;
//        state.usbTxData[l + 4] = 0xFF;
//
//        state.usbTxData[0] = l + 4 + state.usbTxData[12];
      }
      break;
    }
  }
}

void transfer1bit() {
  T2CONbits.ON = 0;
  //  if (state.usbTxData[12] < 63) {
  //    state.usbTxData[state.usbTxData[12]] = (state.sendBeanData.bean) ? (0x80 | state.sendBeanData.cnt) : state.sendBeanData.cnt;
  //    state.usbTxData[12]++;
  //  }  
  PR2 = PR2_VALUE * state.sendBeanData.cnt;
  // Reset cnt so on next call to beanTasks cnt will be recalculted
  // state.sendBeanData.cnt = 0;
  T2CONbits.ON = state.sendBeanData.cnt > 0;
  BEAN_OUT = state.sendBeanData.bean;
  // If cnt is zeor it means that transfer has been ended
  if (state.sendBeanData.cnt) sendBean(&state.sendBeanData);
}

void startSendBean(unsigned char *buffToSend) {
//  state.usbTxData[10] = 0;
//  state.usbTxData[12] = 13;
  initSendBeanData(&state.sendBeanData, buffToSend);
  sendBean(&state.sendBeanData);
  transfer1bit();
}

void terminateBeanSendWithError() {
  T2CONbits.ON = 0;
  resetSendBuffer(&state.sendBeanData);
  state.sendBeanData.sendBeanState = BEAN_TR_ERR;
}

void __attribute__((nomips16)) __attribute__((interrupt(), vector(_TIMER_2_VECTOR))) _timer2Vector(void) {

  IFS0bits.T2IF = 0;
  // It will stop timer if there is no to transfer
  transfer1bit();
}

void __attribute__((nomips16)) __attribute__((interrupt(), vector(_TIMER_3_VECTOR))) _timer3Vector(void) {
  IFS0bits.T3IF = 0;
  T3CONbits.ON = 0; // Timer will be turned on when new bit from BEAN bus will be received
  unsigned char beanIn = BEAN_IN;
  // Put arbitrary large cnt value. As if we're in timer interrupt, it means, that bean bus
  // was not changed for a while. And it is either error or no transfer state.
  recBean(&state.recBeanData, beanIn, 10);
  // We're always reveiving. But in case of USB_BEAN_DEBUG, received command should be sent to USB
  //  if (state.usbCommand == USB_BEAN_DEBUG) sendToUSBReceivedBeanCmd();
}

void inline processBeanInPortChange() {
  T3CONbits.ON = 0;
  unsigned char beanIn = BEAN_IN;
  //  if (isTransferInProgress(&state.sendBeanData) && (!beanIn) != (!state.sendBeanData.bean)) {
  //    terminateBeanSendWithError();
  //  }
  // Always receive. In case of error, timer will be turned off in timer3 interrupt
  uint32_t cnt = TMR3 / state.t3cnt;
  IFS0bits.T3IF = 0;

  //  if (state.usbTxData[12] < 63) {
  //    state.usbTxData[state.usbTxData[12]] = (!beanIn) ? (0x80 | (unsigned char) (TMR3 >> 8)) : (unsigned char) (TMR3 >> 8);
  //    state.usbTxData[state.usbTxData[12] + 1] = (unsigned char) (TMR3);
  //    state.usbTxData[12]+=2;
  //  }  
  TMR3 = 0;
  T3CONbits.ON = 1;
  // reverse beanIn as we want to write to recBeanData already received bits
  // But interrupt is generated on each new bit we're starting to receive
  recBean(&state.recBeanData, !beanIn, cnt);
  // In case of bean bus error, timer will be turned off in timer interrupt
}

