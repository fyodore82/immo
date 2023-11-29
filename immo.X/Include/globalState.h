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
    USB_SPI_GET_REGS = 0x12,

    USB_SEND_BEAN_CMD = 0x21,
    USB_LISTERN_BEAN = 0x22,
    USB_SEND_BEAN_CMD_REC_TICKS = 0x23, // Save ticks elapsed between NEAN IN port change
    USB_LISTERN_BEAN_REC_TICKS = 0x24, // Save ticks elapsed between NEAN IN port change
    USB_SEND_BEAN_CMD_WO_LISTERN = 0x25,

    USB_PLAY_BEEP_SOUND = 0x31,

    USB_GET_GLOBAL_STATE = 0x41,
    USB_MONITOR_GLOBAL_STATE = 0x42,
            
    USB_DISABLE_PERIODIC_IMMO_BEAN_CMD = 0x51,
    USB_ENABLE_PERIODIC_IMMO_BEAN_CMD = 0x52,

    USB_START_BOOTLOADER = 0x80,

    USB_ECHO = 0x90
} USBReqCommand;

typedef enum {
    USB_POST_PORTS_STATE = 3,
    
    USB_POST_SPI_RESP = 0x11,
    USB_POST_SPI_REGS = 0x12,

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

typedef enum {
  IMMO_UNKNOWN,
  IMMO_OK_IMMO,
  IMMO_OK_ASR12V,
  IMMO_ALERT,
} ImmoState;

typedef enum {
  IMMO_IN_UNKNOWN,
  IMMO_IN_OK,
  IMMO_IN_ALERT,
} ImmoInState;

#define SEC_TASK_SEND_GLOBAL_STATE 0b00000001

typedef struct {
    USBReqCommand usbCommand;
    USBSubCommand usbSubCommand;
    unsigned char usbTxData[64];

    ImmoState immoState;
    // When button has been long pressed and each subsequint btn press
    // will switch IMMO_ON 1/0
    unsigned char btnLongPressed;
    // Means that we have already sent notification using BEAN
    unsigned char immoStateChangeNotified;
    uint16_t btnPressSt;
    unsigned char shortPressProcessed;
    unsigned char longPressProcessed;
    // Time when IMMO_ON has been changed.
    uint16_t immoOnOffms;
    // Seems that PIC does not like when try to read output port
    // So store it value in temp var
    unsigned char immoOn;
    // Response received from remote relay
    ImmoInState immoInState;
    // Time, when last cmd was received
    uint16_t immoInLastCmdms;
    // Command LOG_ENTRY_IMMO_IN_5S_DELAY has been sent using SPI
    unsigned char immoIn5msDelaySpiCmdSend;

    // Time. Counts 10ms intervals
    uint16_t ms10;
    uint8_t min;
    uint8_t hour;

    unsigned char secTasks; // Flags to note which task has been executed each sec

    // INIT
    unsigned char initialTasks;

    // BEAN
    RecBeanData recBeanData;
    SendBeanData sendBeanData;
    unsigned char prevBean;
    // To disable periodic immo state commands sent using BEAN
    unsigned char disableImmoBeanSend;

    // To count number of ticks between neigbor bean in port change
    unsigned char recBuff[256];
    unsigned char recPos;

    unsigned char portsState[4];
    unsigned char portsTest[4];

} GlobalState;

extern GlobalState state;

void initGlobalState ();
void sendGlobalState ();
void globalStateTasks ();

#ifdef	__cplusplus
}
#endif

#endif	/* GLOBALSTATE_H */

