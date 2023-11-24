#include "..\Include\sounds.h"
#include "..\Include\globalState.h"
#include "..\Include\ports.h"
#include <xc.h>

// Is array of freq, length in ms
//uint16_t beepSound[] = {
//NOTE_E5, 1000,  NOTE_B4, 2000,  NOTE_C5, 3000,  NOTE_D5, 4000,  NOTE_C5, WHOLE_NOTE / 8,  NOTE_B4, WHOLE_NOTE / 8,
//}
uint16_t nokiaRingtoneSound[] = {
  NOTE_E5, 8, NOTE_D5, 8, NOTE_FS4, 4, NOTE_GS4, 4,
  NOTE_CS5, 8, NOTE_B4, 8, NOTE_D4, 4, NOTE_E4, 4,
  NOTE_B4, 8, NOTE_A4, 8, NOTE_CS4, 4, NOTE_E4, 4,
  NOTE_A4, 2, 0
};

uint16_t startSound[] = {
  NOTE_E5, 8, NOTE_D5, 8, 0 
}; 
//NOTE_FS4, 4, NOTE_GS4, 4,
//  NOTE_A4, 2, 0
//};

void playSound(uint16_t sound[]) {
  if (!sound[0]) return;
  state.soundPlaying = sound;
  state.soundIndex = 0;
  PR4 = (T4_2TICKS_FREQ / sound[state.soundIndex]) * 2;
  TMR4 = 0;

  state.soundLength = (WHOLE_NOTE / sound[state.soundIndex + 1]) * sound[state.soundIndex] / 1000;
  BEEPER_CTRL_OUT = 0;
  T4CONbits.ON = 1;
}

void __attribute__((nomips16)) __attribute__((interrupt(), vector(_TIMER_4_VECTOR))) _timer4Vector(void) {
  T4CONbits.ON = 0;
  IFS0bits.T4IF = 0;
  TMR4 = 0;
  if (!state.beeper_ctrl_out) {
    if (state.soundLength) state.soundLength--;
    else {
      state.soundIndex += 2;
      if (!state.soundPlaying[state.soundIndex]) {
        state.soundPlaying = 0;
        state.soundIndex = 0;
        state.soundLength = 0;
        BEEPER_CTRL_OUT = 0;
        state.beeper_ctrl_out = 0;
        return;
      }
      PR4 = T4_2TICKS_FREQ / state.soundPlaying[state.soundIndex];
      state.soundLength = (WHOLE_NOTE / state.soundPlaying[state.soundIndex + 1]) * state.soundPlaying[state.soundIndex] / 1000;
    }
  }
  state.beeper_ctrl_out = !state.beeper_ctrl_out;
  BEEPER_CTRL_OUT = state.beeper_ctrl_out;
  T4CONbits.ON = 1;
}

