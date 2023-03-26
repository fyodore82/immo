#include <gtest/gtest.h>
#define __32MX220F032B__

#include "immo.X/Source/stateControl.c"

class StateControlTestClass : public ::testing::Test
{
  virtual void SetUp()
  {
    initGlobalState();
  }
};

TEST_F(StateControlTestClass, Should_Turn_On_Immo)
{
  processStateChange();
  EXPECT_EQ(IMMO_ON_OUT, 1);
}