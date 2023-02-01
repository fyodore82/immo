#include <string.h>
#include <stdlib.h>
#include <xc.h>
#include "..\Include\globalState.h"
#include "..\Include\Custom_HID.h"
#include <bean.h>
#include "..\Include\beanTasks.h"
#include "..\Include\ports.h"
#include "..\Include\spi.h"
#include "..\Include\typeConvert.h"
#include "..\Include\sounds.h"

void ProcessRxFrame(unsigned char* UsbRxData, unsigned char len) {
  state.usbCommand = USB_NO_CMD;
  state.usbSubCommand = USB_NO_SUBCMD;
  switch ((USBReqCommand) UsbRxData[0]) {
    case USB_NO_CMD:
      break;

      // ---------------
      // Port commands
      // ---------------
    case USB_GET_PORTS_STATE:
      getPorts();
      break;

    case USB_MONITOR_PORTS_STATE:
      state.usbCommand = USB_MONITOR_PORTS_STATE;
      state.usbSubCommand = USB_NO_SUBCMD;
      break;

    case USB_SET_PORT_STATE0:
    case USB_SET_PORT_STATE1:
      setPorts((USBReqCommand) UsbRxData[0] == USB_SET_PORT_STATE1, &UsbRxData[2]);
      getPorts();
      break;

      // -------------
      // BEAN commands
      // -------------
    case USB_SEND_BEAN_CMD:
    case USB_SEND_BEAN_CMD_REC_TICKS:
      state.usbCommand = (USBReqCommand) UsbRxData[0];
      initSendBeanData(&state.sendBeanData, &UsbRxData[2]);
      state.recBeanData.recBufferFull = 0;
      state.recPos = 0;
      break;

    case USB_LISTERN_BEAN:
    case USB_LISTERN_BEAN_REC_TICKS:
      state.usbCommand = (USBReqCommand) UsbRxData[0];
      state.recPos = 0;
      state.recBeanData.recBufferFull = 0;
      break;


    case USB_SPI_SEND_CMD:
    {
      state.usbCommand = USB_SPI_SEND_CMD;
      state.spiCmd[0] = byteArrToUint32ForSPI(&UsbRxData[2]);
      state.spiCmd[1] = byteArrToUint32ForSPI(&UsbRxData[6]);
      //      memcpy(&state.spiCmd, &UsbRxData[2], 4);
      txSPI();
      break;
    }

    case USB_PLAY_BEEP_SOUND:
      playSound(nokiaRingtoneSound);
      break;

    case USB_ECHO:
    {
      state.usbTxData[0] = 0x01;
      state.usbTxData[1] = USB_ECHO;
      break;
    }

    case USB_START_BOOTLOADER:
    {
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
      while (1);
      break;
    }
  }
}

unsigned char GetTransmitFrame(unsigned char* UsbTxData) {

  if (state.usbTxData[0]) {
    unsigned char BuffLen = state.usbTxData[0];
    memcpy(UsbTxData, &state.usbTxData[1], state.usbTxData[0]);
    state.usbTxData[0] = 0;
    return BuffLen;
  }
  return 0;
}