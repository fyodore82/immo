#include "../Include/initialTasks.h"
#include "../Include/spi.h"
#include "../Include/globalState.h"
#include <xc.h>

void initialTasks() {
  if (state.initialTasks == 0) return;
  if ((state.initialTasks & SPI_FIND_STOP_ADDR) && state.spiTask == SPI_NO_TASK) {
    state.initialTasks ^= SPI_FIND_STOP_ADDR;
    txSPI(0x03000000 | state.spiAddr, 0);
    state.spiTask = SPI_FIND_STOP;
  }
  else if ((state.initialTasks & SPI_WRITE_RESET_REASON) && state.spiTask == SPI_NO_TASK) {
    state.initialTasks ^= SPI_WRITE_RESET_REASON;
    uint32_t data = ((uint8_t)LOG_ENTRY_RESET << 24) + ((uint16_t)RCON << 8) + 0x25;
    RCON = 0;
    writeLog(data);
  }
}
