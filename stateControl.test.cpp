#include <gtest/gtest.h>
#define __32MX220F032B__

#include "mocks/bean.c"
#include "immo.X/Source/typeConvert.c"
#include "immo.X/Source/stateControl.c"
#include "immo.X/Source/globalState.c"

class StateControlTestClass : public ::testing::Test
{
  virtual void SetUp()
  {
  }
};

TEST_F(StateControlTestClass, Should_FirstText)
{
  EXPECT_EQ(0, 0);
}

int main(int argc, char *argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}