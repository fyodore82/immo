#include "..\Include\typeConvert.h"


uint32_t byteArrToUint32ForSPI(unsigned char *byte) {
  // Reverse byte order as most significant should go first
  return byte[3] + (byte[2] << 8) + (byte[1] << 16) + (byte[0] << 24);
}

void uint32ToByteArr(unsigned char *byte, uint32_t uint) {
  byte[0] = (uint8_t) (uint >> 24);
  byte[1] = (uint8_t) (uint >> 16);
  byte[2] = (uint8_t) (uint >> 8);
  byte[3] = (uint8_t) uint;
}
