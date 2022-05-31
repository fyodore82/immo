#include "Custom_HID.h"
#include <string.h>
#include <stdlib.h>
#include <xc.h>

unsigned char txData[64];

void ProcessRxFrame(unsigned char* UsbRxData, unsigned char len)
{
  switch(UsbRxData[0])
  {
    case 0x90: {
      txData[0] = 0x01;
      txData[1] = 0x90;
      break;
    }
    
//    case 0x80: {
//      // Do software reset
//      SYSKEY = 0x00000000; //write invalid key to force lock
//      SYSKEY = 0xAA996655; //write key1 to SYSKEY
//      SYSKEY = 0x556699AA; //write key2 to SYSKEY
//      // OSCCON is now unlocked
//      /* set SWRST bit to arm reset */
//      RSWRSTSET = 1;
//      /* read RSWRST register to trigger reset */
//      unsigned int dummy;
//      dummy = RSWRST;
//      /* prevent any unwanted code execution until reset occurs*/
//      while(1);
//      break;
//	  }
  }
}

unsigned char GetTransmitFrame(unsigned char* UsbTxData)
{
  
  if (txData[0]) 
  {
    unsigned char BuffLen = txData[0];
    memcpy(UsbTxData, &txData[1], txData[0]);
    txData[0] = 0;
    return BuffLen;
  }
  return 0;
}