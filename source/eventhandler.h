#ifndef EVENTHANDLER_H_
#define EVENTHANDLER_H_
#include "MicroBit.h"
#include "pomodoro.h"

extern MicroBit uBit;
int pomodoroMode = 0;  // 0 Standby, 1 Pomodoro, 2 Short Break, 3 Long Break

// Sets the correct pomodoro mode after button press "A"
void eventhandler(MicroBitEvent e) {
    if (e.source == MICROBIT_ID_BUTTON_A) {
        if (pomodoroMode == 0) {
            pomodoroMode = 1;
            pomodoro();
        } else if (pomodoroMode == 1) {
            pomodoroMode = 0;
        } else if (pomodoroMode == 2) {
            pomodoroMode = 1;
            uBit.display.clear();
            pomodoro();
        }
    }
}

#endif
