#include "..\Include\beanTasks.h"
#include "..\Include\globalState.h"
#include <xc.h>
#include "..\Include\ports.h"
#include <string.h>

// Private to this file

void sendToUSBReceivedBeanCmd() {
  // Do not check in recBufferFull as it may be error during transfer
  if (!state.usbTxData[0]) {
    // Always send max length BEAN cmd, as it may be erroneous so don't relate on the length
    // got from first BEAN byte
    unsigned char l = 17; // 17 = DATA (13) + ML + CRC + EOM + RSP
    state.usbTxData[0] = l + 2;
    state.usbTxData[1] = USB_GOT_BEAN_CMD;
    memcpy(&state.usbTxData[2], state.recBeanData.buffer, l);
    state.recBeanData.recBufferFull = 0;
  }
}

void transfer1bit() {
  TMR2 = 0;
  unsigned int bean = state.transBean[state.transPos] & 0x80;
  PR2 = PR2_VALUE * (state.transBean[state.transPos] & 0x0F);
  state.transPos++;
  T2CONbits.ON = state.transPos < state.transLength;
  // set BEAN_OUT last as it may trigger port change interrupt
  BEAN_OUT = !!bean;
  // If cnt is zero it means that transfer has been ended
//  if (state.sendBeanData.cnt) sendBean(&state.sendBeanData);
}

void beanTasks() {
  if (canStartTransfer(state.sendBeanData.sendBeanState, state.recBeanData.recBeanState)) {
    state.transPos = 0;
    state.transLength = 0;
    do {
      sendBean(&state.sendBeanData);
      state.transBean[state.transLength] = state.sendBeanData.bean ? (0x80 | state.sendBeanData.cnt) : state.sendBeanData.cnt;
      state.transLength++;
    } while(state.sendBeanData.cnt);
//    memcpy(&state.usbTxData[3], state.transBean, 62);
//    state.usbTxData[0] = 65;
//    state.usbTxData[1] = USB_SEND_BEAN_CMD;
    state.recPos = 0;
    transfer1bit();
  }

  switch (state.usbCommand) {
    case USB_BEAN_DEBUG:
    {
      if (state.usbSubCommand == BEAN_DEBUG_SET_1) BEAN_OUT = 1;
      if (state.usbSubCommand == BEAN_DEBUG_SET_0) BEAN_OUT = 0;
      // Ports will be chached in ports interrupt

      state.usbSubCommand = USB_NO_SUBCMD;
      break;
    }
    case USB_LISTERN_BEAN:
      if (state.recBeanData.recBufferFull) sendToUSBReceivedBeanCmd();
//        memcpy(&state.usbTxData[3], state.recBuff, 61);
//        state.usbTxData[0] = 63;
//        state.usbTxData[1] = USB_SEND_BEAN_CMD;
//        state.recBeanData.recBufferFull = 0;
//        state.recPos = 0;
//      }
      break;

    case USB_SEND_BEAN_CMD:
    {
      // Check if transfer is in progress as there may be errors during transfer
      // and we still have to send reponse back
      //if (!isTransferInProgress(&state.sendBeanData)) { // && !state.usbTxData[0]) {
      if (state.recBeanData.recBufferFull) {
        state.usbCommand = USB_NO_CMD;
//        sendToUSBReceivedBeanCmd();
        memcpy(&state.usbTxData[3], state.recBuff, 61);
        state.usbTxData[0] = 63;
        state.usbTxData[1] = USB_SEND_BEAN_CMD;
        state.recBeanData.recBufferFull = 0;
        state.recPos = 0;
      }
      break;
    }
  }
}

void terminateBeanSendWithError() {
  T2CONbits.ON = 0;
  resetSendBuffer(&state.sendBeanData);
  state.sendBeanData.sendBeanState = BEAN_TR_ERR;
}

void __attribute__((nomips16)) __attribute__((interrupt(), vector(_TIMER_2_VECTOR))) _timer2Vector(void) {
  T2CONbits.ON = 0;
  IFS0bits.T2IF = 0;
  transfer1bit();
  
//  if (state.writePos + 2 < 61) {
//    uint32_t tm3 = TMR3;
//    state.tempRecBean[state.writePos] = tm3;
//    state.tempRecBean[state.writePos + 1] = state.sendBeanData.bean ? 0xee : 0xdb;
//    state.writePos+=2;
//  }
}

void __attribute__((nomips16)) __attribute__((interrupt(), vector(_TIMER_3_VECTOR))) _timer3Vector(void) {
  IFS0bits.T3IF = 0;
  T3CONbits.ON = 0; // Timer will be turned on when new bit from BEAN bus will be received
  unsigned char beanIn = BEAN_IN;
  // Put arbitrary large cnt value. As if we're in timer interrupt, it means, that bean bus
  // was not changed for a while. And it is either error or no transfer state.
  recBean(&state.recBeanData, beanIn, 10);
}

void inline processBeanInPortChange() {
  T3CONbits.ON = 0;
  unsigned char beanIn = BEAN_IN;
  //  if (isTransferInProgress(&state.sendBeanData) && (!beanIn) != (!state.sendBeanData.bean)) {
  //    terminateBeanSendWithError();
  //  }

  // Always receive. In case of error, timer will be turned off in timer3 interrupt
  uint16_t tm3 = TMR3;
  unsigned char cnt = tm3 / (uint16_t)T3_CNT;
  TMR3 = 0;
  T3CONbits.ON = 1;
  // reverse beanIn as we want to write to recBeanData already received bits
  // But interrupt is generated on each new bit we're starting to receive
  recBean(&state.recBeanData, !beanIn, cnt);
  // In case of bean bus error, timer will be turned off in timer interrupt

//  if (state.recPos < 61) {
//    state.recBuff[state.recPos] = (!beanIn) ? (0x80 | (uint8_t)(tm3 >> 8)) : (uint8_t)(tm3 >> 8);
//    state.recBuff[state.recPos + 1] = tm3; // (!beanIn) ? (0x80 | tm3) : tm3;
//    state.recPos += 2;
//  }
//  if (state.recPos < 61) {
//    state.recBuff[state.recPos] = (!beanIn) ? (0x80 | cnt) : cnt;
//    state.recPos++;
//  }
}

