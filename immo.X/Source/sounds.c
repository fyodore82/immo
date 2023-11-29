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
  NOTE_B4, 8, NOTE_A4, 8, NOTE_CS4, 4, NOTE_E4, 4, 0 
}; 
//NOTE_FS4, 4, NOTE_GS4, 4,
//  NOTE_A4, 2, 0
//};

static uint16_t* soundPlaying;
static unsigned char soundIndex;
static uint16_t soundLength; // length of the sound in TMR4 expirations
                              // Depending on the playing freq, TMR4 may expire earlier of later
static unsigned char beeper_ctrl_out; // PIC does not like when reading from output port

void playSound(uint16_t sound[]) {
  if (!sound[0]) return;
  soundPlaying = sound;
  soundIndex = 0;
  PR4 = (T4_2TICKS_FREQ / sound[soundIndex]) * 2;
  TMR4 = 0;

  soundLength = (WHOLE_NOTE / sound[soundIndex + 1]) * sound[soundIndex] / 1000;
  BEEPER_CTRL_OUT = 0;
  T4CONbits.ON = 1;
}

void __attribute__((nomips16)) __attribute__((interrupt(), vector(_TIMER_4_VECTOR))) _timer4Vector(void) {
  T4CONbits.ON = 0;
  IFS0bits.T4IF = 0;
  TMR4 = 0;
  if (!beeper_ctrl_out) {
    if (soundLength) soundLength--;
    else {
      soundIndex += 2;
      if (!soundPlaying[soundIndex]) {
        soundPlaying = 0;
        soundIndex = 0;
        soundLength = 0;
        BEEPER_CTRL_OUT = 0;
        beeper_ctrl_out = 0;
        return;
      }
      PR4 = T4_2TICKS_FREQ / soundPlaying[soundIndex];
      soundLength = (WHOLE_NOTE / soundPlaying[soundIndex + 1]) * soundPlaying[soundIndex] / 1000;
    }
  }
  beeper_ctrl_out = !beeper_ctrl_out;
  BEEPER_CTRL_OUT = beeper_ctrl_out;
  T4CONbits.ON = 1;
}

