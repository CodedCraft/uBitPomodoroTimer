#include "MicroBit.h"
#include "buzzer.h"

extern MicroBit uBit;
bool pomodoro();
void shortbreak();

static int mode = 0;

void modeSetter() {
    static bool timer = false;
    static bool shortbreak = false;
    static bool longbreak = false;

    if (!timer) {
        timer = true;
        timer = pomodoro();
    }

    /*switch (mode) {  // 1 = standby, 2 = pomodoro timer, 3 = shortbreak, 4 =
                     // long break, 5 = settings
        case 1:      // start pomodoro timer
            pomodoro();
            break;
        case 2:  // break pomodoro and go back to standby
            mode = 0;
            break;
        case 3:  // cut short break short and start new pomodoro
            pomodoro();
            mode = 1;
            break;
        case 4:  // cut long break short and start new pomodoro
            pomodoro();
            mode = 1;
            break;
    }
    */
}

bool pomodoro() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            uBit.display.image.setPixelValue(j, i, 255);
        }
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k <= 60; k++) {
                uBit.display.image.setPixelValue(j, i, (255 - (k * 4.25)));
                // uBit.sleep(978);
                // uBit.sleep(1);
                wait_us(500);
            }
        }
    }
    mode = 2;
    buzzer();
    shortbreak();
    return false;
}

void shortbreak() {
    uBit.display.setDisplayMode(
        DISPLAY_MODE_GREYSCALE);  // Enable per pixel rendering, with 256 level
    for (int j = 4; j >= 0; j--) {
        for (int k = 0; k <= 60; k++) {
            for (int i = 0; i < 5; i++) {
                uBit.display.image.setPixelValue(i, j, 4.25 * k);
            }
            // uBit.sleep(1000);
            wait_us(2000);
        }
    }
    buzzer();
    mode = 0;
    uBit.display.clear();
}
