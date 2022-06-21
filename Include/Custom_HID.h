/* 
 * File:   Custom_HID.h
 * Author: fedor
 *
 * Created on 23 ??? 2022 ?., 19:34
 */

#ifndef CUSTOM_HID_H
#define	CUSTOM_HID_H

#ifdef	__cplusplus
extern "C" {
#endif
#include <stdlib.h>
    #define FRAMEWORK_BUFF_SIZE					64
    #define MaxUsbPacketSize 64

//    typedef UINT8 UsbRxDataType[MaxUsbPacketSize];
//    typedef UINT8 UsbTxDataType[FRAMEWORK_BUFF_SIZE];
//    extern static UINT8 UsbRxData[MaxUsbPacketSize];
//    extern static UINT8 UsbTxData[FRAMEWORK_BUFF_SIZE];
    void ProcessRxFrame(unsigned char* UsbRxData, unsigned char len);
    unsigned char GetTransmitFrame(unsigned char* UsbTxData);

#define FRAMEWORK_BuildRxFrame  			ProcessRxFrame
#define FRAMEWORK_GetTransmitFrame 			GetTransmitFrame
   

#ifdef	__cplusplus
}
#endif

#endif	/* CUSTOM_HID_H */

