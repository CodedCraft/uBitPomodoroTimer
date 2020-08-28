#ifndef _EVENTHANDLER_H
#define _EVENTHANDLER_H
#include "MicroBit.h"

void eventhandler(MicroBitEvent e)
{
    if (e.source == MICROBIT_ID_BUTTON_A)
    {
       if (timerMode = 0)
        {
            pomodoro();
            timerMode = 1: 
        }
       if (timerMode = 1)
        {
            pomodoroBreak();
            timerMode = 1: 
        }
       if (timerMode = 2)
        {
            pomodoroBreak();
            timerMode = 0: 
        }

    }
}
#endif