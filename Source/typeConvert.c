#include "..\Include\typeConvert.h"


uint32_t byteArrToUint32(unsigned char *byte) {
  return byte[0] + (byte[1] << 8) + (byte[2] << 16) + (byte[3] << 24);
}

void uint32ToByteArr(unsigned char *byte, uint32_t uint) {
  byte[0] = (uint8_t) (uint >> 24);
  byte[1] = (uint8_t) (uint >> 16);
  byte[2] = (uint8_t) (uint >> 8);
  byte[3] = (uint8_t) uint;
}

