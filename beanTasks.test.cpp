#include <gtest/gtest.h>
#define __32MX220F032B__

#include "immo.X/Source/beanTasks.c"
#include <list>

// uint8_t immoOutAlertCmd[] = {0x13, 0x33, 0x44, 0x21, 0x01};

class BeanTasksTestClass : public ::testing::Test
{
  virtual void SetUp()
  {
    initGlobalState();
    bean_mock = 0;
    cnt_mock = 0;

    TMR2 = 0;
    PR2 = 0;

    T2CONbits.ON = 0;
    BEAN_OUT = 0;
    BEAN_IN = 0;

    sendBeanCalledTimes = 0;
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

TEST_F(BeanTasksTestClass, beanTasks_Should_start_transfer)
{
  state.sendBeanData.sendBeanState = BEAN_NO_TR_DATA_PRESENT;
  memcpy(state.sendBeanData.sendBuffer, immoOutAlertCmd, (immoOutAlertCmd[0] & 0x0F) + 2);
  state.sendBeanData.cnt = 1;
  state.sendBeanData.bean = 1;

  beanTasks();

  EXPECT_EQ(sendBeanCalledTimes, 2);

  EXPECT_EQ(T2CONbits.ON, 1);
  EXPECT_NE(PR2, 0);  // Hard to check PR2
  EXPECT_EQ(TMR2, 0);
  EXPECT_EQ(state.prevBean, 1);
  EXPECT_EQ(BEAN_OUT, 1);
}

TEST_F(BeanTasksTestClass, beanTasks_Should_NOT_start_transfer_if_no_data_present)
{
  state.sendBeanData.sendBeanState = BEAN_NO_TR;

  beanTasks();

  EXPECT_EQ(sendBeanCalledTimes, 0);

  EXPECT_EQ(T2CONbits.ON, 0);
  EXPECT_EQ(BEAN_OUT, 0);
}

TEST_F(BeanTasksTestClass, _timer2Vector_should_call_transfer1bit)
{
  T2CONbits.ON = 1;
  IFS0bits.T2IF = 1;
  state.sendBeanData.cnt = 3;
  state.sendBeanData.bean = 0;

  _timer2Vector();

  EXPECT_EQ(IFS0bits.T2IF, 0);

  EXPECT_EQ(sendBeanCalledTimes, 1);
  EXPECT_EQ(T2CONbits.ON, 1);
  EXPECT_NE(PR2, 0);  // Hard to check PR2
  EXPECT_EQ(TMR2, 0);
  EXPECT_EQ(state.prevBean, 0);
  EXPECT_EQ(BEAN_OUT, 0);
}

TEST_F(BeanTasksTestClass, _timer2Vector_should_naot_call_sendBean_if_cnt_is_0)
{
  T2CONbits.ON = 1;
  IFS0bits.T2IF = 1;
  state.sendBeanData.cnt = 0;
  state.sendBeanData.bean = 0;

  _timer2Vector();

  EXPECT_EQ(IFS0bits.T2IF, 0);

  EXPECT_EQ(sendBeanCalledTimes, 0);
  EXPECT_EQ(T2CONbits.ON, 0);
  EXPECT_EQ(PR2, 0);  // Hard to check PR2
  EXPECT_EQ(TMR2, 0);
  EXPECT_EQ(state.prevBean, 0);
  EXPECT_EQ(BEAN_OUT, 0);
}