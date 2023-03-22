#include "..\Include\StateControl.h"
#include "..\Include\ports.h"
#include "..\Include\globalState.h"

void processStateChange() {
  if (!IMMO_ON_OUT && state.portsState[BUTTON_IN_IDX]) {
    // Turn on Immo
    IMMO_ON_OUT = 1;
  }
  if (state.sec % 4 == 0 && (state.portsState[IMMO_SENCE_IDX] || state.portsState[ASR12V_IN_IDX])) {
    
  }
}
