#include "Custom_HID.h"
#include <string.h>
#include <stdlib.h>

unsigned char txData[64];

void ProcessRxFrame(unsigned char* UsbRxData, unsigned char len)
{
  switch(UsbRxData[0])
  {
    case 0x90: {
      txData[0] = 0x01;
      txData[1] = 0x90;
    }
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