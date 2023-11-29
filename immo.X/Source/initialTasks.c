#include "../Include/initialTasks.h"
#include "../Include/spi.h"
#include "../Include/globalState.h"
#include <xc.h>
#include "..\Include\sounds.h"

void initialTasks() {
  if (state.initialTasks == 0) return;
  // Welcome Sound should be played last
  if ((state.initialTasks & PLAY_WELCOME_SOUND) && state.ms10 >= 100) {
    state.initialTasks ^= PLAY_WELCOME_SOUND;
    playSound(startSound);
  }
}
