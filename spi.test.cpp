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

    sendIdxBottom = 0;
    sendIdxTop = 0;
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

// sendToSpi

TEST_F(SpiTestClass, sendToSpi)
{
  uint32_t addr = 0x12345678;
  uint32_t data = 0x87654321;
  sendToSpi(addr, data);
  EXPECT_EQ(spiSend[0], addr);
  EXPECT_EQ(spiSend[1], data);
  EXPECT_EQ(sendIdxBottom, 2);
}

// processSpiSend

TEST_F(SpiTestClass, processSpiSend_should_send_first_data)
{
  IFS1bits.SPI1RXIF = 1;
  state.ms10 = 10;

  spiSend[0] = 0x12345678;
  spiSend[1] = 0x87654321;
  sendIdxBottom = 2;
  spiIsStopFound = 1;

  processSpiSend();

  EXPECT_EQ(SPI1BUF.idx, 2);
  EXPECT_EQ(SPI1BUF.l[0], spiSend[0]);
  EXPECT_EQ(SPI1BUF.l[1], spiSend[1]);
  EXPECT_EQ(sendIdxTop, 2);
}

// logSpi

TEST_F(SpiTestClass, logSpi_with_SMALL_SECTOR_ERASE)
{
  uint32_t initialAddr = 0x1000 | (SPI_SMALL_SECTOR - 8);
  spiAddr = initialAddr;
  logSpi(LOG_ENTRY_RESET);

  EXPECT_EQ(spiSend[0], 0x06000000);
  EXPECT_EQ(spiSend[1], 0);

  EXPECT_EQ(spiSend[2], 0x02000000 | initialAddr);
  EXPECT_EQ(spiSend[3], (state.hour << 24) | (state.min << 16) | state.ms10);

  EXPECT_EQ(spiSend[4], 0x06000000);
  EXPECT_EQ(spiSend[5], 0);

  EXPECT_EQ(spiSend[6], 0x02000000 | (initialAddr + 4));
  // Do not check 7 as it complicated
  // EXPECT_EQ(spiSend[7], ...);

  EXPECT_EQ(spiSend[8], 0xd7000000 | (initialAddr + 8));
  EXPECT_EQ(spiSend[9], 0);
}