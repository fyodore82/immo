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
  if ((state.initialTasks & SPI_WRITE_RESET_REASON) && state.spiTask == SPI_NO_TASK) {
    state.initialTasks ^= SPI_WRITE_RESET_REASON;
    state.logType = LOG_ENTRY_RESET;
//    RCON = 0;
  }
}
