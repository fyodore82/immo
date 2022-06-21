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

#define BEAN_IN PORTBbits.RB9
#define BEAN_IN_CNSTAT CNSTATBbits.CNSTATB9

void beanTasks ();


#ifdef	__cplusplus
}
#endif

#endif	/* BEANTASKS_H */

