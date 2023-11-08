#ifndef _XC_H
#define _XC_H

#define _UNIT_TEST_

struct {
  unsigned int RB0;
  unsigned int RB4;
  unsigned int RB5;
  unsigned int RB7;
  unsigned int RB8;
  unsigned int RB9;
  unsigned int RB13;
  unsigned int RB15;
} PORTBbits;

// struct {
//   unsigned int RA4;
// } PORTAbits;

struct {
  unsigned int CNSTATB0;
  unsigned int CNSTATB4;
  unsigned int CNSTATB5;
  unsigned int CNSTATB7;
  unsigned int CNSTATB8;
  unsigned int CNSTATB13;
  unsigned int CNSTATB15;
} CNSTATBbits;

struct {
  unsigned int ON;
} T3CONbits;

struct {
  unsigned int ON;
} T2CONbits;

struct {
  unsigned int T3IF;
  unsigned int T2IF;
} IFS0bits;

#define nomips16
#define __attribute__(a)
#define _TIMER_2_VECTOR
#define _TIMER_3_VECTOR
#define vector(a)
#define interrupt(a)

uint16_t TMR3;
uint16_t TMR2;
uint16_t PR2;

uint16_t RCON;

void __delay_ms(int value);

class SPI1BUFType {
public:
  uint32_t l[10];
  uint32_t idx;
  SPI1BUFType() {
    idx = 0;
  }
  uint32_t operator=(const uint32_t other)
  {
    l[idx] = other;
    return l[idx++];
  }

  operator uint32_t() const {
    return idx > 0 ? l[idx - 1] : 0;
  }
} SPI1BUF;

struct {
  unsigned int SPI1RXIF;
  unsigned int SPI1TXIF;
} IFS1bits;

#endif