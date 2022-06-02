#include "../Include/addressConvertion.h"
#include <xc.h>

void mapIOPorts ()
{
  unsigned int int_status;
  int_status = INTDisableInterrupts();
  
  SYSKEY = 0x00000000; //write invalid key to force lock
  SYSKEY = 0xAA996655; //write key1 to SYSKEY
  SYSKEY = 0x556699AA; //write key2 to SYSKEY
  
  CFGCONbits.PMDLOCK = 0;

  SYSKEY = 0x00000000; //write invalid key to force lock
  PMD1 = 0xFF;
  PMD2 = 0xFF;
  
  PMD3bits.OC1MD = 1;
  PMD3bits.OC2MD = 1;
  PMD3bits.OC3MD = 1;
  PMD3bits.OC4MD = 1;
  PMD3bits.OC5MD = 1;
  
  PMD5bits.I2C1MD = 1;
  PMD5bits.I2C2MD = 1;
  PMD5bits.SPI1MD = 1;
  PMD5bits.SPI2MD = 1;
  PMD5bits.U1MD = 1;
  PMD5bits.U2MD = 1;
  PMD6 = 0xFF;
  
    SYSKEY = 0x00000000; //write invalid key to force lock
  SYSKEY = 0xAA996655; //write key1 to SYSKEY
  SYSKEY = 0x556699AA; //write key2 to SYSKEY
  
  CFGCONbits.IOLOCK = 0;

  SYSKEY = 0x00000000; //write invalid key to force lock
  
  INTRestoreInterrupts(int_status);
}


void initIOPorts ()
{

}
