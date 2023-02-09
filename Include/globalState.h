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
#include "spi.h"
    
typedef enum {
    USB_NO_CMD,
//    USB_BEAN_DEBUG,
    USB_GET_PORTS_STATE = 2,
    USB_SET_PORT_STATE0 = 3,  // Data[0] = port number
    USB_SET_PORT_STATE1 = 4,  // Data[0] = port number
//    USB_MONITOR_PORTS_STATE = 5, // Cannot monitor as CN int has higher priority than USB and will freeze device
            
    USB_SPI_SEND_CMD = 0x11,
            
    USB_SEND_BEAN_CMD = 0x21,
    USB_LISTERN_BEAN = 0x22,
    USB_SEND_BEAN_CMD_REC_TICKS = 0x23, // Save ticks elapsed between NEAN IN port change
    USB_LISTERN_BEAN_REC_TICKS = 0x24, // Save ticks elapsed between NEAN IN port change
            
    USB_PLAY_BEEP_SOUND = 0x31,
            
    USB_GET_GLOBAL_STATE = 0x41,
    USB_MONITOR_GLOBAL_STATE = 0x42,
    
    USB_START_BOOTLOADER = 0x80,            

    USB_ECHO = 0x90
} USBReqCommand;

typedef enum {
    USB_POST_PORTS_STATE = 3,
    USB_POST_SPI_RESP = 0x11,
            
    USB_GOT_BEAN_CMD = 0x21,
    USB_GOT_REC_TICKS = 0x23,
            
    USB_GOT_GLOBAL_STATE = 0x41,

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
    unsigned char usbTxData[64];
    
    // INIT
    unsigned char initialTasks;
    
    // BEAN
    RecBeanData recBeanData;
    SendBeanData sendBeanData;
    unsigned char prevBean;
    
    // To count number of ticks between neigbor bean in port change
    unsigned char recBuff[256];
    unsigned char recPos;
    
    // SPI
    uint32_t spiReceive[4];  // We're going to receive up to 4 spi cmd
    unsigned char spiRecIdx;
    uint32_t spiSend[SPI_SEND_BUFF]; // 0 - addr, 1 - data, 2 - addr, 1 - data
    unsigned char spiSendIdx;

    SPITask spiTask;
    uint32_t spiAddr;   // Current SPI address to write log to
    
    // Sounds
    uint16_t* soundPlaying;
    unsigned char soundIndex;
    uint16_t soundLength; // length of the sound in TMR4 expirations
                          // Depending on the playing freq, TMR4 may expire earlier of later
    unsigned char portsState[4];
    unsigned char portsTest[4];
    
} GlobalState;

extern GlobalState state;

void initGlobalState ();
void sendGlobalState ();
void processGlobalStateChange();


#ifdef	__cplusplus
}
#endif

#endif	/* GLOBALSTATE_H */

