#ifndef BUZZER_H_
#define BUZZER_H_
#include "MicroBit.h"

extern MicroBit uBit;
void buzzer() {
    uBit.io.P0.setAnalogValue(511);
    uBit.io.P0.setAnalogPeriodUs(1200);
    wait(0.15);
    uBit.io.P0.setAnalogPeriodUs(0);
    wait(0.05);
    uBit.io.P0.setAnalogPeriodUs(1200);
    wait(0.15);
    uBit.io.P0.setAnalogPeriodUs(0);
    wait(0.05);
    uBit.io.P0.setAnalogPeriodUs(1200);
    wait(0.15);
    uBit.io.P0.setAnalogPeriodUs(0);
    wait(0.05);
    uBit.io.P0.setAnalogPeriodUs(1200);
    wait(0.15);
    uBit.io.P0.setAnalogPeriodUs(0);
    wait(0.05);
    uBit.io.P0.setAnalogPeriodUs(1200);
    wait(0.15);
    uBit.io.P0.setAnalogPeriodUs(0);

    //release_fiber();
}
#endif
