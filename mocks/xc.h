#ifndef _XC_H
#define _XC_H

#define _UNIT_TEST_

struct {
  unsigned int RB0;
  unsigned int RB4;
  unsigned int RB5;
  unsigned int RB7;
  unsigned int RB8;
  unsigned int RB13;
  unsigned int RB15;
} PORTBbits;

struct {
  unsigned int RA4;
} PORTAbits;

struct {
  unsigned int CNSTATB0;
  unsigned int CNSTATB4;
  unsigned int CNSTATB5;
  unsigned int CNSTATB7;
  unsigned int CNSTATB8;
  unsigned int CNSTATB13;
  unsigned int CNSTATB15;
} CNSTATBbits;

void __delay_ms(int value) {}

#endif