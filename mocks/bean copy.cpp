#include <bean.h>
#include <gtest/gtest.h>
#include <gmock/gmock.h>  // Brings in gMock.

class CBeanFunctionsMock
{
public:
    static CBeanFunctionsMock* instance;

    CBeanFunctionsMock() {
        instance = this;
    }

    ~CBeanFunctionsMock() {
        instance = nullptr;
    }

    MOCK_METHOD(unsigned char, initSendBeanData, (SendBeanData *pBeanData, unsigned char *buff));
    MOCK_METHOD(void, resetRecBuffer, (RecBeanData *pBeanData));
    MOCK_METHOD(void, resetSendBuffer, (SendBeanData *pBeanData));

};

CBeanFunctionsMock* CBeanFunctionsMock::instance = nullptr;

void resetRecBuffer(RecBeanData *pBeanData) {
  ASSERT_NE(CBeanFunctionsMock::instance, nullptr);
  CBeanFunctionsMock::instance->resetRecBuffer(pBeanData);
}
void resetSendBuffer(SendBeanData *pBeanData) {
  ASSERT_NE(CBeanFunctionsMock::instance, nullptr);
  CBeanFunctionsMock::instance->resetSendBuffer(pBeanData);
}
unsigned char initSendBeanData(SendBeanData *pBeanData, unsigned char *buff) {
    if (CBeanFunctionsMock::instance == nullptr) {
        ADD_FAILURE() << "CBeanFunctionsMock::instance == nullptr";
        return 0;
    }

    return CBeanFunctionsMock::instance->initSendBeanData(pBeanData, buff);
}