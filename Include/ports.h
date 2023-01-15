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

#define BEEPER_CTRL_OUT PORTBbits.RB15  // pin 26
#define IMMO_ON_OUT PORTAbits.RA4       // pin 12
#define BEAN_OUT PORTBbits.RB13         // pin 24

#define BUTTON_IN PORTBbits.RB0
#define BUTTON_IN_CNSTAT CNSTATBbits.CNSTATB0

#define CAPOT_IN PORTBbits.RB4
#define CAPOT_IN_CNSTAT CNSTATBbits.CNSTATB4

#define IMMO_SENCE_IN PORTBbits.RB5
#define IMMO_SENCE_IN_CNSTAT CNSTATBbits.CNSTATB5

#define ASR12V_IN PORTBbits.RB7
#define ASR12V_IN_CNSTAT CNSTATBbits.CNSTATB7

#define BEAN_IN PORTBbits.RB8
#define BEAN_IN_CNSTAT CNSTATBbits.CNSTATB8

#ifdef	__cplusplus
}
#endif

#endif	/* PORTS_H */

