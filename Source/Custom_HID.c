#include <string.h>
#include <stdlib.h>
#include <xc.h>
#include "..\Include\globalState.h"
#include "..\Include\Custom_HID.h"
#include <bean.h>
#include "..\Include\beanTasks.h"
#include "..\Include\ports.h"
#include "..\Include\spi.h"

void ProcessRxFrame(unsigned char* UsbRxData, unsigned char len)
{
  switch((USBReqCommand)UsbRxData[0])
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
    
    case USB_SEND_BEAN_CMD: {
      state.usbCommand = USB_SEND_BEAN_CMD;
      startSendBean(&UsbRxData[2]);
      //state.usbTxData[0] = 2;
      //state.usbTxData[1] = UsbRxData[2];
      //state.usbTxData[2] = UsbRxData[3];
      break;
    }
    
    case USB_GET_PORTS_STATE: {
      state.usbTxData[0] = 9;
      state.usbTxData[1] = USB_POST_PORTS_STATE;
      getPorts(&state.usbTxData[2]);
      break;
    }
    
    case USB_SPI_SEND_CMD: {
      state.usbCommand = USB_SPI_SEND_CMD;
      uint32_t spi;
      memcpy(&spi, &UsbRxData[2], 4);
      txSPI(spi);
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