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
    USB_SEND_BEAN_CMD,
    USB_GET_PORTS_STATE,
            
    USB_SPI_SEND_CMD = 0x11,
    
    USB_START_BOOTLOADER = 0x80,            

    USB_ECHO = 0x90
} USBReqCommand;

typedef enum {
    USB_REC_BEAN = 2,
    USB_POST_PORTS_STATE = 3,
    USB_POST_SPI_RESP = 0x11,
} USBRespCommand;

typedef enum {
    USB_NO_SUBCMD,
    BEAN_DEBUG_SET_1,
    BEAN_DEBUG_SET_0
} USBSubCommand;


typedef struct {
    USBReqCommand usbCommand;
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

