#include "..\Include\USB\addressConvertion.h"
#include <xc.h>
#include <proc/p32mx220f032b.h>
#include "..\Include\beanTasks.h"

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
  PMD3 = 0xFF;
  
//  PMD3bits.OC1MD = 1;
//  PMD3bits.OC2MD = 1;
//  PMD3bits.OC3MD = 1;
//  PMD3bits.OC4MD = 1;
//  PMD3bits.OC5MD = 1;
  
  PMD5bits.I2C1MD = 1;
  PMD5bits.I2C2MD = 1;
//  PMD5bits.SPI1MD = 1;
  PMD5bits.SPI2MD = 1;
  PMD5bits.U1MD = 1;
  PMD5bits.U2MD = 1;
 
  PMD6 = 0xFF;
  CFGCONbits.PMDLOCK = 1; // Disable PMD
  
  SYSKEY = 0x00000000; //write invalid key to force lock
  
  // ------------ init ports -----------------
  PORTA = 0;
  PORTB = 0;
  LATA = 0;
  LATB = 0;
  
  // 12.2.4 ODCx. ODCx for all ports are 0 on reset = normal digital output, NOT open-drain
  
  // 12.2.5 ANSELx. Set all ports to digital.
  ANSELA = 0x0;
  ANSELB = 0x0;

  // 12.3.3 Change notification
  // Enable for RPB9, BEAN_IN
  // ToDo: remove weak pull downs
  CNCONBbits.ON = 1;
  
  // V pin 4
  CNENBbits.CNIEB0 = 1;
  unsigned char readPort = PORTBbits.RB0;
  CNPDBbits.CNPDB0 = 1;

  // pin 11
  CNENBbits.CNIEB4 = 1;
  readPort = PORTBbits.RB4;
  CNPDBbits.CNPDB4 = 1;
  
  // V pin 12
  TRISAbits.TRISA4 = 0;
  PORTAbits.RA4 = 0;

  // V pin 14
  TRISBbits.TRISB5 = 0;
  PORTBbits.RB5 = 0;

  // ToDo - remove after testing
  // V pin 16
  CNENBbits.CNIEB7 = 1;
  readPort = PORTBbits.RB7;

  // pin 17: BEAN_IN
  CNENBbits.CNIEB8 = 1;
  readPort = PORTBbits.RB8;
  
  // X pin 18
  CNPDBbits.CNPDB9 = 1;

  // V Set 24 pin (RPB13) to output. It is BEAN_OUT
  TRISBbits.TRISB13 = 0;
  
  // V pin 26
  CNPDBbits.CNPDB15 = 1;
  
  IPC8bits.CNIP = 0x7;
  IPC8bits.CNIS = 0x3;
  IFS1bits.CNBIF = 0;
  
  IEC1bits.CNBIE = 1;
  // Interrupts will be enabled as part of TRANS_LAYER_Init() in main()
  
  // ------------------ Peripherial Pin Select ------------------
  // By default all pins connected to digital i/o
  SYSKEY = 0x00000000; //write invalid key to force lock
  SYSKEY = 0xAA996655; //write key1 to SYSKEY
  SYSKEY = 0x556699AA; //write key2 to SYSKEY
  
  CFGCONbits.IOLOCK = 0;  // Allow remapping
  SDI1R = 0b0010; // SDI1 -> RPB1 (pin 5)
  RPB2R = 0b0011; // RPB2 -> SDO1 (pin 6)
  RPB3R = 0b0011; // RPB3 -> SS1 (pin7)
  CFGCONbits.IOLOCK = 1;  // Disable rmapping

  SYSKEY = 0x00000000; //write invalid key to force lock
 
  // --------- Timers ---------
  T2CON = T2CON_VALUE;
  TMR2 = 0x0;
  PR2 = PR2_VALUE;   
  IFS0bits.T2IF = 0;
  IPC2bits.T2IP = 1;
  IPC2bits.T2IS = 1;
  IEC0bits.T2IE = 1;

  T3CON = T3CON_VALUE;
  TMR3 = 0x0;
  PR3 = PR3_VALUE;   
  IFS0bits.T3IF = 0;
  IPC3bits.T3IP = 1;
  IPC3bits.T3IS = 1;
  IEC0bits.T3IE = 1;
  
  // ----------------- SPI -------------------
  // Config REFOCON 
  SPI1BUF = 0;
//  IFS1 = 0;
//  IPC7bits.SPI1IP = 1;
//  IPC7bits.SPI1IS = 1;
//  IEC1bits.SPI1EIE = 1; - no need for SPI error interrupts
  // IEC1bits.SPI1RXIE = 1;
//  IEC1bits.SPI1TXIE = 1;
  // SPI1BRG = 0; - zero on reset. Fsck = Fpb / (2 * (SPI1BRG + 1)) = 40 MHz / (2 * (0 + 1)) = 20 MHz
  SPI1STATbits.SPIROV = 0;
  // bit 0-1: SRXISEL<1:0>: SPI Receive Buffer Full Interrupt Mode bits = 01 = buffer is not empty
  // bit 5: MSTEN = 1 - master
  // bit 6: CKP: Clock Polarity Select bit = 0 (low = idle)
  // bit 8: CKE: SPI Clock Edge Select bit = 1
  // bit 9: SMP: SPI Data Input Sample Phase bit = 1
  // bit 11-10 MODE<32,16> = 11 - 32bit
  // bit 15 ON: SPI Peripheral On bit = 0
  // bit 16 ENHBUF: Enhanced Buffer Enable bit = 1
  // bit 28 MSSEN: Master Mode Slave Select Enable bit = 1

  //          |4th by||3rd by||2nd by||1st bt|
  SPI1CON = 0b00010000000000011000111100100001;
  // _SS is required on scheme, as it should be rised when transmittion finished
  
  INTRestoreInterrupts(int_status);
}