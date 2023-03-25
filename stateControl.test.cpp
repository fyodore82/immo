#include <gtest/gtest.h>
#define __32MX220F032B__

#include "immo.X/Source/stateControl.c"

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