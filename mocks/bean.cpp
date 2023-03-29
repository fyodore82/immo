#include <bean.h>
#include <gtest/gtest.h>
// #include "..\immo.X\Include\spi.h
#include <list>
// #include <gmock/gmock.h>  // Brings in gMock.

// class CBeanMockBase {
//   public:
//     void resetRecBuffer(RecBeanData *pBeanData) {}
//     void resetSendBuffer(SendBeanData *pBeanData) {}
//     unsigned char initSendBeanData(SendBeanData *pBeanData, unsigned char *buff) {
//       return 0;
//     }
// };

// class CBeanFunctionsMock : public CBeanMockBase
// {
// public:
//     CBeanFunctionsMock() {
//     }

//     ~CBeanFunctionsMock() {
//     }

//     MOCK_METHOD(unsigned char, initSendBeanData, (SendBeanData *pBeanData, unsigned char *buff));
//     MOCK_METHOD(void, resetRecBuffer, (RecBeanData *pBeanData));
//     MOCK_METHOD(void, resetSendBuffer, (SendBeanData *pBeanData));

// };

// CBeanFunctionsMock* instance = new CBeanFunctionsMock();

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