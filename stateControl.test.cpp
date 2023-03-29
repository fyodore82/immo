#include <gtest/gtest.h>
#define __32MX220F032B__

#include "immo.X/Source/stateControl.c"
#include <list>

class StateControlTestClass : public ::testing::Test
{
  virtual void SetUp()
  {
    initGlobalState();
    initSendBeanDataBuff.clear();
    IMMO_ON_OUT = 0;
  }
};

TEST_F(StateControlTestClass, Should_Turn_On_Immo)
{
  state.ms10 = 0;
  processStateChange();
  EXPECT_EQ(IMMO_ON_OUT, 1);
  EXPECT_EQ(initSendBeanDataBuff.size(), 0);
  EXPECT_EQ(state.immoState, IMMO_UNKNOWN);
  EXPECT_EQ(state.immoOnOffms, state.ms10);
}

TEST_F(StateControlTestClass, Nothing_should_happen_if_less_than_10_ms_elapsed_after_IMMO_ON_OFF)
{
  uint16_t ms10Initial = 12;
  state.ms10 = ms10Initial;
  processStateChange();
  EXPECT_EQ(IMMO_ON_OUT, 1);
  EXPECT_EQ(initSendBeanDataBuff.size(), 0);
  EXPECT_EQ(state.immoState, IMMO_UNKNOWN);
  EXPECT_EQ(state.immoOnOffms, state.ms10);

  state.ms10 += 9;
  processStateChange();

  EXPECT_EQ(initSendBeanDataBuff.size(), 0);
  EXPECT_EQ(state.immoState, IMMO_UNKNOWN);
  EXPECT_EQ(state.immoOnOffms, ms10Initial);
}

TEST_F(StateControlTestClass, Should_Send_immoOutOkCmd_when_IMMO_SENCE_is_1)
{
  state.ms10 = 9;

  IMMO_ON_OUT = 1;
  state.portsState[IMMO_SENCE_IDX] = 1;

  processStateChange();
  EXPECT_EQ(IMMO_ON_OUT, 1);
  EXPECT_EQ(initSendBeanDataBuff.size(), 1);
  EXPECT_EQ(state.immoState, IMMO_OK);
  auto arg = initSendBeanDataBuff.back();
  std::vector<uint8_t> immoOk;
  immoOk.assign(immoOutOkCmd, immoOutOkCmd + ((immoOutOkCmd[0] & 0x0F) + 2));
  EXPECT_EQ(arg, immoOk);
}

TEST_F(StateControlTestClass, Should_Send_bean_cmd_every_4_ms)
{
  state.ms10 = 9;

  IMMO_ON_OUT = 1;
  state.immoState = IMMO_OK;
  state.portsState[IMMO_SENCE_IDX] = 1;
  processStateChange();

  state.ms10 = 400;
  processStateChange();

  EXPECT_EQ(IMMO_ON_OUT, 1);
  EXPECT_EQ(initSendBeanDataBuff.size(), 1);
  EXPECT_EQ(state.immoState, IMMO_OK);
  auto arg = initSendBeanDataBuff.back();
  std::vector<uint8_t> immoOk;
  immoOk.assign(immoOutOkCmd, immoOutOkCmd + ((immoOutOkCmd[0] & 0x0F) + 2));
  EXPECT_EQ(arg, immoOk);
}

TEST_F(StateControlTestClass, Should_Switch_to_Alert_when_IMMO_SENCE_is_0)
{
  state.ms10 = 9;

  IMMO_ON_OUT = 1;
  state.portsState[IMMO_SENCE_IDX] = 1;

  processStateChange();
  EXPECT_EQ(IMMO_ON_OUT, 1);
  EXPECT_EQ(initSendBeanDataBuff.size(), 1);
  EXPECT_EQ(state.immoState, IMMO_OK);

  state.portsState[IMMO_SENCE_IDX] = 0;

  processStateChange();
  EXPECT_EQ(IMMO_ON_OUT, 1);
  EXPECT_EQ(initSendBeanDataBuff.size(), 2);
  EXPECT_EQ(state.immoState, IMMO_ALERT);

  auto arg = initSendBeanDataBuff.back();
  std::vector<uint8_t> immoAlert;
  immoAlert.assign(immoOutAlertCmd, immoOutAlertCmd + ((immoOutAlertCmd[0] & 0x0F) + 2));
  EXPECT_EQ(arg, immoAlert);
}

TEST_F(StateControlTestClass, When_ASR12V_is_1_immo_is_turned_off_and_state_is_IMMO_OK)
{
  state.ms10 = 9;

  state.portsState[ASR12V_IN_IDX] = 1;

  processStateChange();
  EXPECT_EQ(IMMO_ON_OUT, 0);
  EXPECT_EQ(initSendBeanDataBuff.size(), 1);
  EXPECT_EQ(state.immoState, IMMO_OK);

  auto arg = initSendBeanDataBuff.back();
  std::vector<uint8_t> immoOk;
  immoOk.assign(immoOutOkCmd, immoOutOkCmd + ((immoOutOkCmd[0] & 0x0F) + 2));
  EXPECT_EQ(arg, immoOk);
}

TEST_F(StateControlTestClass, Btn_Short_press_should_do_nothing_if_not_preceeded_by_long_press)
{
  state.ms10 = 9;
  state.portsState[BUTTON_IN_IDX] = 1;

  processStateChange();

  EXPECT_EQ(state.btnPressSt, state.ms10);
  EXPECT_EQ(state.longPressProcessed, 0);
  EXPECT_EQ(state.shortPressProcessed, 0);
  EXPECT_EQ(state.longPressProcessed, 0);

  state.ms10 += 20;
  state.portsState[BUTTON_IN_IDX] = 0;

  processStateChange();

  EXPECT_EQ(state.btnPressSt, 0xFFFF);
  EXPECT_EQ(state.longPressProcessed, 0);
  EXPECT_EQ(state.shortPressProcessed, 0);
  EXPECT_EQ(state.longPressProcessed, 0);
}

TEST_F(StateControlTestClass, Btn_Long_press)
{
  uint16_t initialMs10 = 9;
  state.ms10 = initialMs10;
  state.portsState[BUTTON_IN_IDX] = 1;

  processStateChange();

  EXPECT_EQ(state.btnPressSt, state.ms10);
  EXPECT_EQ(state.longPressProcessed, 0);
  EXPECT_EQ(state.shortPressProcessed, 0);
  EXPECT_EQ(state.longPressProcessed, 0);
  EXPECT_EQ(IMMO_ON_OUT, 1);

  state.ms10 += 100;

  processStateChange();

  EXPECT_EQ(state.btnPressSt, 0xFFFF);
  EXPECT_EQ(state.longPressProcessed, 1);
  EXPECT_EQ(state.shortPressProcessed, 1);
  EXPECT_EQ(state.longPressProcessed, 1);
  EXPECT_EQ(IMMO_ON_OUT, 0);
}

TEST_F(StateControlTestClass, Each_short_press_after_long_press_should_change_IMMO_ON_OUT)
{
  state.ms10 = 88;
  state.btnLongPressed = 1;

  // Press again
  state.portsState[BUTTON_IN_IDX] = 1;
  processStateChange();

  EXPECT_EQ(state.btnPressSt, state.ms10);
  EXPECT_EQ(state.btnLongPressed, 1);
  EXPECT_EQ(state.shortPressProcessed, 1);
  EXPECT_EQ(state.longPressProcessed, 0);
  EXPECT_EQ(IMMO_ON_OUT, 1);
}

TEST_F(StateControlTestClass, Long_press_should_out_from_btnLongPressed_state)
{
  state.btnLongPressed = 1;
  state.ms10 = 15;

  // Press again
  state.portsState[BUTTON_IN_IDX] = 1;
  processStateChange();

  EXPECT_EQ(state.btnPressSt, state.ms10);
  EXPECT_EQ(state.btnLongPressed, 1);

  state.ms10 += 100;
  processStateChange();

  EXPECT_EQ(state.btnPressSt, 0xFFFF);
  EXPECT_EQ(state.btnLongPressed, 0);

}