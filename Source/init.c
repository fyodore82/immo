#include "..\Include\USB\addressConvertion.h"
#include <xc.h>

void init ()
{
  unsigned int int_status;
  int_status = INTDisableInterrupts();
  
  // PMD tested using USB module disable
  SYSKEY = 0x00000000; //write invalid key to force lock
  SYSKEY = 0xAA996655; //write key1 to SYSKEY
  SYSKEY = 0x556699AA; //write key2 to SYSKEY
  
  CFGCONbits.PMDLOCK = 0;

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
  
  // 12.2.4 ODCx. ODCx for all ports are 0 on reset = normal digital output, NOT open-drain
  
  // 12.2.5 ANSELx. Set all ports to digital.
  ANSELA = 0x0;
  ANSELB = 0x0;
  
  // 12.2.6 Change notification
  // Enable for RPB9, BEAN_IN
  CNENBbits.CNIEB9 = 1;
  // ToDo - remove after testing
  CNENBbits.CNIEB7 = 1;
  CNENBbits.CNIEB8 = 1;
  CNCONBbits.ON = 1;
  
  // 12.2.7 Peripherial Pin Select
  // By default all pins connected to digital i/o
    
//  SYSKEY = 0x00000000; //write invalid key to force lock
//  SYSKEY = 0xAA996655; //write key1 to SYSKEY
//  SYSKEY = 0x556699AA; //write key2 to SYSKEY
//  
//  CFGCONbits.IOLOCK = 0;
//
//  SYSKEY = 0x00000000; //write invalid key to force lock

  // Set (RPB9) to input. It is BEAN_IN
  TRISBbits.TRISB9 = 1;
  // Set 24 pin (RPB13) to output. It is BEAN_OUT
  TRISBbits.TRISB13 = 0;
  
  INTRestoreInterrupts(int_status);
}