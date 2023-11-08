#include <gtest/gtest.h>
#define __32MX220F032B__

#include "immo.X/Source/beanTasks.c"
#include <list>

class BeanTasksTestClass : public ::testing::Test
{
  virtual void SetUp()
  {
    initGlobalState();
    bean_mock = 0;
    cnt_mock = 0;
  }
};

TEST_F(BeanTasksTestClass, processBeanInPortChange_Should_receive_single_bit)
{
  BEAN_IN = 1;
  TMR3 = 4;
  processBeanInPortChange();

  EXPECT_EQ(bean_mock, 0);  // Reverse of BEAN is sent to recBean
  EXPECT_EQ(cnt_mock, 4);
  EXPECT_EQ(TMR3, 0);
  EXPECT_EQ(T3CONbits.ON, 1);
  EXPECT_EQ(state.sendBeanData.sendBeanState, BEAN_NO_TR);
}

TEST_F(BeanTasksTestClass, processBeanInPortChange_Should_set_send_error_condition)
{
  // Sent bean bit and received does not match - error condition
  BEAN_IN = 1;
  state.prevBean = 0;
  BEAN_OUT = 1;
  state.sendBeanData.sendBeanState = BEAN_TR_SOF;
  TMR3 = 4;
  processBeanInPortChange();

  EXPECT_EQ(state.sendBeanData.sendBeanState, BEAN_TR_ERR);
  EXPECT_EQ(BEAN_OUT, 0);
}