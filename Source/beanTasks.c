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

void sendToUSBReceivedRecBuff() {
  // Do not check in recBufferFull as it may be error during transfer
  if (!state.usbTxData[0]) {
    state.usbTxData[0] = 63;
    state.usbTxData[1] = USB_GOT_REC_TICKS;
    memcpy(&state.usbTxData[2], state.recBuff, 61);
    state.recPos = 0;
    state.recBeanData.recBufferFull = 0;
  }
}

void transfer1bit() {
  TMR2 = 0;
  // Ajust send length to make it ideal
  PR2 = (PR2_VALUE * state.sendBeanData.cnt) + (state.sendBeanData.bean ? -0x0F : 0x0F);
  T2CONbits.ON = !!state.sendBeanData.cnt;
  BEAN_OUT = state.sendBeanData.bean;
  // Is used to check if sent BEAN bit is equal to what is really on the BUS
  state.prevBean = state.sendBeanData.bean;
  // If cnt is zero it means that transfer has been ended
  if (state.sendBeanData.cnt) sendBean(&state.sendBeanData);
}

// ----------- PUBLIC ----------------

void beanTasks() {
  if (canStartTransfer(state.sendBeanData.sendBeanState, state.recBeanData.recBeanState)) {
    sendBean(&state.sendBeanData);
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
      break;
    case USB_LISTERN_BEAN_REC_TICKS:
      if (state.recBeanData.recBufferFull) sendToUSBReceivedRecBuff();
      break;

    case USB_SEND_BEAN_CMD:
      // Check if transfer is in progress as there may be errors during transfer
      // and we still have to send reponse back
      if (state.recBeanData.recBufferFull) {
        state.usbCommand = USB_NO_CMD;
        sendToUSBReceivedBeanCmd();
      }
      break;
    case USB_SEND_BEAN_CMD_REC_TICKS:
      if (state.recBeanData.recBufferFull) {
        state.usbCommand = USB_NO_CMD;
        sendToUSBReceivedRecBuff();
      }
      break;
  }
}

//void terminateBeanSendWithError() {
//  T2CONbits.ON = 0;
//  resetSendBuffer(&state.sendBeanData);
//  state.sendBeanData.sendBeanState = ;
//}

void __attribute__((nomips16)) __attribute__((interrupt(), vector(_TIMER_2_VECTOR))) _timer2Vector(void) {
  T2CONbits.ON = 0;
  IFS0bits.T2IF = 0;
  // Check for send error condition and rest it to restart sending
  if (resetSendError(&state.sendBeanData)) return;
  transfer1bit();
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
//  unsigned char beanOut = BEAN_OUT;
  if (isTransferInProgress(&state.sendBeanData) && beanIn != state.prevBean) {
    // Just turn write error condition to beand send
    // Timer 2 will be used to reset bean error condition to restart sending
    // when bus will be ready
    setSendError(&state.sendBeanData);
    BEAN_OUT = 0;
    // In case of bus error condition do not return.
    // Always receive. In case of error, timer will be turned off in timer3 interrupt
  }
  
  uint16_t tm3 = TMR3;
  unsigned char cnt = getCntFromTmr(tm3, T3_CNT);
  TMR3 = 0;
  T3CONbits.ON = 1;
  // reverse beanIn as we want to write to recBeanData already received bits
  // But interrupt is generated on each new bit we're starting to receive
  recBean(&state.recBeanData, !beanIn, cnt);
  // In case of bean bus error, timer will be turned off in timer interrupt
  
  // We'll save only remainder from division
  if ((state.usbCommand == USB_LISTERN_BEAN_REC_TICKS || state.usbCommand == USB_SEND_BEAN_CMD_REC_TICKS)
    && state.recPos < 61) {
    unsigned char rem = tm3 - ((tm3 / T3_CNT) * T3_CNT);
    state.recBuff[state.recPos] = (!beanIn) ? (0x80 | cnt) : cnt;
    state.recBuff[state.recPos + 1] = rem;
    state.recPos += 2;
  }
}

