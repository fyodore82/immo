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
#include <xc.h>
    
typedef enum {
    USB_NO_CMD,
    USB_BEAN_DEBUG,
    USB_GET_PORTS_STATE,
            
    USB_SPI_SEND_CMD = 0x11,
            
    USB_SEND_BEAN_CMD = 0x21,
    USB_LISTERN_BEAN = 0x22,
    USB_SEND_BEAN_CMD_REC_TICKS = 0x23, // Save ticks elapsed between NEAN IN port change
    USB_LISTERN_BEAN_REC_TICKS = 0x24, // Save ticks elapsed between NEAN IN port change
    
    USB_START_BOOTLOADER = 0x80,            

    USB_ECHO = 0x90
} USBReqCommand;

typedef enum {
    USB_POST_PORTS_STATE = 3,
    USB_POST_SPI_RESP = 0x11,
            
    USB_GOT_BEAN_CMD = 0x21,
    USB_GOT_REC_TICKS = 0x23,

    // USB_ECHO = 0x90
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
    unsigned char prevBean;

    unsigned char usbTxData[64];
    
    // To count number of ticks between neigbor bean in port change
    unsigned char recBuff[256];
    unsigned char recPos;
    // SPI
    uint32_t spiCmd[4];
    // We're going to receive up to 4 spi cmd
    uint32_t spiReceive[4];
    unsigned char spiRecIdx;
} GlobalState;

extern GlobalState state;

void initGlobalState ();


#ifdef	__cplusplus
}
#endif

#endif	/* GLOBALSTATE_H */

