/*
 * File:   StateControl.h
 * Author: fedor
 *
 * Created on March 22, 2023, 7:24 PM
 */

#ifndef STATECONTROL_H
#define	STATECONTROL_H

#ifdef	__cplusplus
extern "C" {
#endif

void processStateChange();

extern uint8_t immoInOkCmd[];
extern uint8_t immoInAlertCmd[];

#ifdef	__cplusplus
}
#endif

#endif	/* STATECONTROL_H */

