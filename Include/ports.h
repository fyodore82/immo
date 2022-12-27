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

#define BEEPER_CTRL_OUT PORTBbits.RB15
#define IMMO_ON_OUT PORTAbits.RA4


#ifdef	__cplusplus
}
#endif

#endif	/* PORTS_H */

