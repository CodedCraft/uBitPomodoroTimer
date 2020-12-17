#include "MicroBit.h"
#include "MicroBitFiber.h"
#include "MicroBitListener.h"
#include "batteryTester.h"
#include "eventhandler.h"

MicroBit uBit;

bool debugMode = false;
int pomodoroTime = 975;
int breakTime = 980; 

int main() {
    // Initialise the micro:bit runtime.
    uBit.init();

    // Enable per pixel rendering, with 256 level of brightness per pixel.
    uBit.display.setDisplayMode(DISPLAY_MODE_GREYSCALE);
    MicroBitEvent e;
    uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_CLICK,
                           eventhandler, MESSAGE_BUS_LISTENER_URGENT);

    if (debugMode == true) {
        pomodoroTime = 1;
    }
    // Ring buzzer to notify startup of program
    buzzer();

    // Entering a power efficient sleep and waking up periodically to poll the battery 
    while (1) {
        uBit.sleep(100000);
        batteryCheck();
    }
}
