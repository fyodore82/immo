/* 
 * File:   ports.h
 * Author: fedor
 *
 * Created on 24 ???? 2022 ?., 17:39
 */

#ifndef PORTS_H
#define	PORTS_H

#ifdef	__cplusplus
extern "C" {
#endif

void getPorts();
void setPorts(unsigned char, unsigned char*);
unsigned char getPortStateByIdx(uint8_t idx);
void processPortsChange();

#define BEEPER_CTRL_OUT PORTBbits.RB15  // pin 26
#define IMMO_ON_OUT PORTAbits.RA4       // pin 12
#define BEAN_OUT PORTBbits.RB13         // pin 24

#define BUTTON_IN PORTBbits.RB0
#define BUTTON_IN_CNSTAT CNSTATBbits.CNSTATB0
#define BUTTON_IN_IDX 0

#define CAPOT_IN PORTBbits.RB4
#define CAPOT_IN_CNSTAT CNSTATBbits.CNSTATB4
#define CAPOT_IN_IDX 1

#define IMMO_SENCE_IN PORTBbits.RB5
#define IMMO_SENCE_IN_CNSTAT CNSTATBbits.CNSTATB5
#define IMMO_SENCE_IDX 2

#define ASR12V_IN PORTBbits.RB7
#define ASR12V_IN_CNSTAT CNSTATBbits.CNSTATB7
#define ASR12V_IN_IDX 3

#define BEAN_IN PORTBbits.RB8
#define BEAN_IN_CNSTAT CNSTATBbits.CNSTATB8

#define T5CON_VALUE 0x00008070 // ON = 1, TCKPS = 256, T32 = 0, TSC = 0
#define PR5_VALUE 0x061A       // = ~10ms

#define BUTTON_TEST_STATE_MID 0x10   // Middle, neither 0 or 1
#define BUTTON_TEST_STATE_ONE 0x13   // One State
#define BUTTON_TEST_STATE_ZERO 0x0D   // Zero State

#ifdef	__cplusplus
}
#endif

#endif	/* PORTS_H */

