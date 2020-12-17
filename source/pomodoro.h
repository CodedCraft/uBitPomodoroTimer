#ifndef POMODORO_H_
#define POMODORO_H_
#include "MicroBit.h"
#include "buzzer.h"
#include "images.h"
#include "pomodoroCounter.h"

extern MicroBit uBit;
extern int pomodoroTime;
extern int breakTime;
extern int pomodoroMode;

// Starts break, "breakTime" from "pomodoroCounter.h" defines the break lenght
void pomodoroBreak() {
    int r = uBit.random(5);  // store a random value between 0 and 5 in "r"
    for (int j = 4; j >= 0; j--) {
        for (int k = 0; k <= 60; k++) {
            for (int i = 0; i < 5; i++) {
                // display random picture "r" from images.h from the bottom
                uBit.display.image.setPixelValue(i, j,
                                                 4.25 * k * images[r][j][i]);
                // if a button A is pressed the break stops & a pomodoro starts
                if (pomodoroMode == 1) {
                    return;
                }
            }
            uBit.sleep(breakTime);
        }
    }
    buzzer();
    uBit.display.clear();
    pomodoroMode = 0;
}

// starts a pomodoro
void pomodoro() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            uBit.display.image.setPixelValue(j, i, 255);
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k <= 60; k++) {
                uBit.display.image.setPixelValue(j, i, (255 - (k * 4.25)));

                if (pomodoroMode == 0) {
                    uBit.display.clear();
                    return;
                }
                uBit.sleep(pomodoroTime);
            }
        }
    }
    buzzer();
    pomodoroMode = 2;
    // counts a pomodoro and sets the breaktime accordingly to 5 or 15min
    breakTime = pomodoroCounter();
    // starts the a break automatically after the pomodoro has finished
    pomodoroBreak();
}

#endif
