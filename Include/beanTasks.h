/* 
 * File:   beanTasks.h
 * Author: fedor
 *
 * Created on 20 ???? 2022 ?., 19:55
 */

#ifndef BEANTASKS_H
#define	BEANTASKS_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <xc.h>

#define BEAN_OUT PORTBbits.RB13

#define BEAN_IN PORTBbits.RB8
#define BEAN_IN_CNSTAT CNSTATBbits.CNSTATB8
    
// Timer2 is used to send BEAN
#define T2CON_VALUE 0x00000050 // ON = 0, TCKPS = 32, T32 = 0, TSC = 0
#define PR2_VALUE 0x007D   // = 125 ticks for 10kbps

// Timer3 is used to receive BEAN
#define T3CON_VALUE 0x00000050 // ON = 0, TCKPS = 32, T32 = 0, TSC = 0
#define T3_CNT 0x0060       // 0x7D = 125 ticks for 10kbps.
                            // Is decreased so when dividing TimerValue to T3CNT we gen number of bits
                            // as sending freq can diviate
#define PR3_VALUE T3_CNT * 7    // Is used to detect bean bus idle state
    
void beanTasks ();
void startSendBean(unsigned char *buffToSend);
void terminateBeanSendWithError();
void processBeanInPortChange();

#ifdef	__cplusplus
}
#endif

#endif	/* BEANTASKS_H */

