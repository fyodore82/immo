#include <gtest/gtest.h>
#define __32MX220F032B__

#include "immo.X/Source/spi.c"

class SpiTestClass : public ::testing::Test
{
  virtual void SetUp()
  {
    initGlobalState();
    SPI1BUF.idx = 0;
    spiIsStopFound = 0;
  }
};

TEST_F(SpiTestClass, tsSPI_should_write_to_SPI1BUF)
{
  uint32_t addr = 0x12345678;
  uint32_t data = 0x22334455;
  txSPI(addr, data);
  EXPECT_EQ(SPI1BUF.idx, 2);
  EXPECT_EQ(SPI1BUF.l[0], addr);
  EXPECT_EQ(SPI1BUF.l[1], data);
}

// findStop
TEST_F(SpiTestClass, findStop_first_call_should_call_txSPI)
{
  findStop();
  EXPECT_EQ(SPI1BUF.idx, 2);
  EXPECT_EQ(SPI1BUF.l[0], 0x03000000 | SPI_INITIAL_ADDR);
  EXPECT_EQ(SPI1BUF.l[1], 0);
  EXPECT_EQ(spiAddr, SPI_INITIAL_ADDR + 8);
}

TEST_F(SpiTestClass, findStop_second_call_should_only_read_SPI1BUF)
{
  spiAddr = SPI_INITIAL_ADDR + 8;
  IFS1bits.SPI1RXIF = 1;
  uint32_t data = 0x33445566;
  SPI1BUF = data;
  findStop();
  EXPECT_EQ(SPI1BUF.idx, 1);
  EXPECT_EQ(SPI1BUF.l[0], data);
}

TEST_F(SpiTestClass, findStop_second_call_should_only_read_SPI1BUF_again_and_check_for_stop)
{
  spiAddr = SPI_INITIAL_ADDR + 8;
  IFS1bits.SPI1RXIF = 1;
  SPI1BUF = 0x33445566;
  SPI1BUF = 0xFFFFFFFF;
  findStop();
  findStop();
  EXPECT_EQ(SPI1BUF.idx, 2);
  EXPECT_EQ(spiIsStopFound, 1);
  EXPECT_EQ(spiAddr, SPI_INITIAL_ADDR);
}

TEST_F(SpiTestClass, findStop_if_stop_not_found_shpuld_read_next_word)
{
  spiAddr = SPI_INITIAL_ADDR + 8;
  IFS1bits.SPI1RXIF = 1;
  SPI1BUF = 0x33445566;
  SPI1BUF = 0x12345678;
  findStop();
  findStop();
  EXPECT_EQ(SPI1BUF.idx, 4);
  EXPECT_EQ(SPI1BUF.l[2], 0x03000000 | (SPI_INITIAL_ADDR + 8));
  EXPECT_EQ(SPI1BUF.l[3], 0);
  EXPECT_EQ(spiAddr, SPI_INITIAL_ADDR + 16);
  EXPECT_EQ(spiIsStopFound, 0);
}

TEST_F(SpiTestClass, findStop_if_approached_end_of_memory_reset_to_SPI_INITIAL_ADDR)
{
  spiAddr = SPI_MAX_ADDR;
  IFS1bits.SPI1RXIF = 1;
  SPI1BUF = 0x33445566;
  SPI1BUF = 0x12345678;
  findStop();
  findStop();
  EXPECT_EQ(SPI1BUF.idx, 2);
  EXPECT_EQ(spiIsStopFound, 1);
  EXPECT_EQ(spiAddr, SPI_INITIAL_ADDR);
}