#include <gtest/gtest.h>
#define __32MX220F032B__

#include "mocks/bean.cpp"
#include "immo.X/Source/typeConvert.c"
#include "immo.X/Source/globalState.c"
#include <xc.h>

#include "stateControl.test.cpp"
#include "spi.test.cpp"

void __delay_ms(int value) {}

int main(int argc, char *argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}