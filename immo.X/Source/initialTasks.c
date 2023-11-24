#include "../Include/initialTasks.h"
#include "../Include/spi.h"
#include "../Include/globalState.h"
#include <xc.h>
#include "..\Include\sounds.h"

void initialTasks() {
  if (state.initialTasks == 0) return;
  if (!state.spiIsStopFound && state.spiTask == SPI_NO_TASK && state.ms10 >= 5) {
    txSPI(0x03000000 | state.spiAddr, 0);
    state.spiTask = SPI_FIND_STOP;
  }
  if ((state.initialTasks & SPI_WRITE_RESET_REASON) && state.spiTask == SPI_NO_TASK && state.logType == DONT_LOG) {
    state.initialTasks ^= SPI_WRITE_RESET_REASON;
    state.logType = LOG_ENTRY_RESET;
  }
  // Welcome Sound should be played last
  if ((state.initialTasks & PLAY_WELCOME_SOUND) && state.ms10 >= 100) {
    state.initialTasks ^= PLAY_WELCOME_SOUND;
    playSound(startSound);
  }
}
