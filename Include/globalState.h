/* 
 * File:   globalState.h
 * Author: fedor
 *
 * Created on 20 ???? 2022 ?., 17:16
 */

#ifndef GLOBALSTATE_H
#define	GLOBALSTATE_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#include <bean.h>
    
typedef enum {
    USB_NO_CMD,
    USB_BEAN_DEBUG,
    
    USB_START_BOOTLOADER = 0x80,            

    USB_ECHO = 0x90
} USBCommand;

typedef enum {
    USB_NO_SUBCMD,
    BEAN_DEBUG_SET_1,
    BEAN_DEBUG_SET_0
} USBSubCommand;


typedef struct {
    USBCommand usbCommand;
    USBSubCommand usbSubCommand;
    RecBeanData recBeanData;
    SendBeanData sendBeanData;
    unsigned char usbTxData[64];
} GlobalState;

extern GlobalState state;

void initGlobalState ();


#ifdef	__cplusplus
}
#endif

#endif	/* GLOBALSTATE_H */

