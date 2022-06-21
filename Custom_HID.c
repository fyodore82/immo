#include "Custom_HID.h"
#include <string.h>
#include <stdlib.h>
#include <xc.h>
#include ".\Include\globalState.h"

void ProcessRxFrame(unsigned char* UsbRxData, unsigned char len)
{
  switch(UsbRxData[0])
  {
    case USB_NO_CMD: {
      state.usbCommand = USB_NO_CMD;
      state.usbSubCommand = USB_NO_SUBCMD;
      break;
    }

    // BEAN commands
    case USB_BEAN_DEBUG: {
      state.usbCommand = USB_BEAN_DEBUG;
      state.usbSubCommand = UsbRxData[1];
      break;
    }

    case USB_ECHO: {
      state.usbTxData[0] = 0x01;
      state.usbTxData[1] = USB_ECHO;
      break;
    }
    
    case USB_START_BOOTLOADER: {
      // Do software reset
      SYSKEY = 0x00000000; //write invalid key to force lock
      SYSKEY = 0xAA996655; //write key1 to SYSKEY
      SYSKEY = 0x556699AA; //write key2 to SYSKEY
      // OSCCON is now unlocked
      /* set SWRST bit to arm reset */
      RSWRSTSET = 1;
      /* read RSWRST register to trigger reset */
      unsigned int dummy;
      dummy = RSWRST;
      /* prevent any unwanted code execution until reset occurs*/
      while(1);
      break;
	  }
  }
}

unsigned char GetTransmitFrame(unsigned char* UsbTxData)
{
  
  if (state.usbTxData[0]) 
  {
    unsigned char BuffLen = state.usbTxData[0];
    memcpy(UsbTxData, &state.usbTxData[1], state.usbTxData[0]);
    state.usbTxData[0] = 0;
    return BuffLen;
  }
  return 0;
}