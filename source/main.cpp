#include "MicroBit.h"
//#include "source/pomodorobreak.h"
//#include "eventhandler.h"
MicroBit uBit;

void pomodoroBreak();
void eventhandler();
void pomodoro();
int main();
int completed = 0;
int timerMode = 0; //0 = main menu, 1 = pomodoromode, 2 = short break, 3 = long break

void eventhandler(MicroBitEvent e)
{
    if (e.source == MICROBIT_ID_BUTTON_A)
    {
        if (timerMode == 0)
        {
            timerMode = 1;
            pomodoro();
        }
        if (timerMode == 1)
        {
            timerMode = 2;
            pomodoroBreak();
        }
        if (timerMode == 2)
        {
            timerMode = 0;
            main();
        }
    }
}
void pomodoro()
{

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            uBit.display.image.setPixelValue(j, i, 255);
        }
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k <= 60; k++)
            {
                uBit.display.image.setPixelValue(j, i, (255 - (k * 4.25)));
                //uBit.sleep(978);
                uBit.sleep(1);
            }
        }

        completed++;
        uBit.storage.put("Completed", (uint8_t *)&completed, sizeof(int));
        timerMode = 2;
        pomodoroBreak();
    }
}

void pomodoroBreak()
{
    uBit.serial.printf("Break started");
    for (int j = 4; j >= 0; j--)
    {
        for (int k = 0; k <= 60; k++)
        {
            for (int i = 0; i < 5; i++)
            {
                uBit.display.image.setPixelValue(i, j, 4.25 * k);
            }
            //uBit.sleep(1000);
            uBit.sleep(1);
        }
    }
    uBit.display.clear();
    timerMode = 0;
}

int main()
{
    // Initialise the micro:bit runtime.
    uBit.init();

    uBit.display.setDisplayMode(DISPLAY_MODE_GREYSCALE);
    MicroBitEvent e;
    uBit.messageBus.listen(MICROBIT_ID_BUTTON_A, MICROBIT_BUTTON_EVT_CLICK, eventhandler);
    /*Keep track of pomodoros: 
    int done;
    KeyValuePair *numberOfPomodoros = uBit.storage.get("Completed");
    memcpy(&completed, numberOfPomodoros->value, sizeof(int));
    done = completed;
    completed = 0;
    uBit.storage.put("Completed", (uint8_t *)&completed, sizeof(int));
    delete numberOfPomodoros;
    uBit.display.scroll(completed);
    uBit.sleep(2000);
    uBit.display.scroll(done);
    */

    // Enable per pixel rendering, with 256 level of brightness per pixel.
    //someotherfunction();
    while (1)
        uBit.sleep(10000);
}
