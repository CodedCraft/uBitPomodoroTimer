#include "./buzzer.h"
#include "./pomodoro.h"
#include "MicroBit.h"
#include "MicroBitFiber.h"
void eventhandler(MicroBitEvent e);

// Mode that the Pomododor timer is currently in:
// 0 = standby, 1 = pomodoro timer, 2 = shortbreak, 3 = long break, 4 = settings
// static int mode = 0;

MicroBit uBit;

int main() {
    // Initialise the micro:bit runtime.
    uBit.init();
    uBit.display.setDisplayMode(
        DISPLAY_MODE_GREYSCALE);  // Enable per pixel rendering, with 256 level
                                  // of brightness per pixel.

    MicroBitEvent e;
    uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_CLICK,
                           eventhandler);
    buzzer(); //launches buzzer in buzzer.h

    // Looping function
    uBit.sleep(10000);
}

void eventhandler(MicroBitEvent e) {
    if (e.source == MICROBIT_ID_BUTTON_A) {
        modeSetter();
    }
}

