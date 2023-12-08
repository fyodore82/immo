#include <bean.h>
#include <gtest/gtest.h>
// #include "..\immo.X\Include\spi.h
#include <list>
// #include <gmock/gmock.h>  // Brings in gMock.

std::list<std::vector<unsigned char>> initSendBeanDataBuff;

void resetRecBuffer(RecBeanData *pBeanData) {
  // ASSERT_NE(CBeanFunctionsMock::instance, nullptr);
  // instance->resetRecBuffer(pBeanData);
}
void resetSendBuffer(SendBeanData *pBeanData) {
  // ASSERT_NE(CBeanFunctionsMock::instance, nullptr);
  // CBeanFunctionsMock::instance->resetSendBuffer(pBeanData);
}
// void writeLog(SPILogEntryType logType) {

// }
unsigned char initSendBeanData(SendBeanData *pBeanData, unsigned char *buff) {
  std::vector<unsigned char> v;
  v.assign(buff, buff + ((buff[0] & 0x0F) + 2));
  initSendBeanDataBuff.push_back(v);
    // if (CBeanFunctionsMock::instance == nullptr) {
    //     ADD_FAILURE() << "CBeanFunctionsMock::instance == nullptr";
    //     return 0;
    // }

    // return CBeanFunctionsMock::instance->initSendBeanData(pBeanData, buff);
  return 0;
}

char bean_mock;
unsigned char cnt_mock;

void recBean(RecBeanData *, char bean, unsigned char cnt) {
  bean_mock = bean;
  cnt_mock = cnt;
}

unsigned char getCntFromTmr(unsigned short tmr, unsigned short)
{
  // For simlicity in testing
  return tmr;
}

void setSendError(SendBeanData *pBeanData) {
  pBeanData->sentBit = 7;
  pBeanData->sendBuffPos = 0;
  pBeanData->cnt = 0;
  pBeanData->sendBeanState = BEAN_TR_ERR;

  pBeanData->sendNextBitStaffing = 0;
  pBeanData->bean = 0;
}

unsigned char sendBeanCalledTimes;

void sendBean(SendBeanData *pBeanData) {
  sendBeanCalledTimes++;
}

unsigned char isTransferInProgress(SendBeanData *pBeanData) {
  return pBeanData->sendBeanState == BEAN_TR_SOF;
}

unsigned char canStartTransfer(BeanTransferState sendBeanState, BeanTransferState recBeanState) {
  return sendBeanState == BEAN_NO_TR_DATA_PRESENT && recBeanState == BEAN_NO_TR;
}

void resetSendError(SendBeanData *pBeanData, unsigned char beanIn, unsigned char cnt) {
}
