#include <gtest/gtest.h>
#define __32MX220F032B__

#include "immo.X/Source/spi.c"

class SpiTestClass : public ::testing::Test
{
  virtual void SetUp()
  {
    initGlobalState();
  }
};

TEST_F(SpiTestClass, Should_Send_Data)
{
  state.spiSend[0] = 0x06000000;
  state.spiSend[1] = 0x0;
  state.spiSend[2] = 0x02001122;
  state.spiSend[3] = 0x12345678;
  state.spiSend[4] = 0x06000000;
  state.spiSend[5] = 0x0;
  state.spiSend[6] = 0x02112233;
  state.spiSend[7] = 0x87654321;
  state.spiSend[8] = 0;

  state.ms10 = 201;

  state.spiTask = SPI_SEND_DATA;
  IFS1bits.SPI1TXIF = 1;

  // First call - send first word to SPI bus
  spiTasks();
  EXPECT_EQ(state.lstSpiSendCmd, state.ms10);
  EXPECT_EQ(state.spiSendIdx, 2);
  EXPECT_EQ(SPI1BUF.idx, 2);
  EXPECT_EQ(SPI1BUF.l[0], state.spiSend[0]);
  EXPECT_EQ(SPI1BUF.l[1], state.spiSend[1]);

  // Second call during same ms - nothing should happen
  spiTasks();
  EXPECT_EQ(state.lstSpiSendCmd, state.ms10);
  EXPECT_EQ(state.spiSendIdx, 2);
  EXPECT_EQ(SPI1BUF.idx, 2);

  // Third call during after 20 ms - send second word to SPI bus
  state.ms10 += 2;
  spiTasks();
  EXPECT_EQ(state.lstSpiSendCmd, state.ms10);
  EXPECT_EQ(state.spiSendIdx, 4);
  EXPECT_EQ(SPI1BUF.idx, 4);
  EXPECT_EQ(SPI1BUF.l[2], state.spiSend[2]);
  EXPECT_EQ(SPI1BUF.l[3], state.spiSend[3]);

  // Send all other data
  state.ms10 += 2;
  spiTasks();
  state.ms10 += 2;
  spiTasks();
  EXPECT_EQ(state.spiTask, SPI_NO_TASK);
  EXPECT_EQ(state.lstSpiSendCmd, 0xFFFF);
  EXPECT_EQ(state.spiSendIdx, 0);
}