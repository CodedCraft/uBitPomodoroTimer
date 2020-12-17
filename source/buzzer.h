#ifndef BUZZER_H_
#define BUZZER_H_
#include "MicroBit.h"

// Uses pulse width modulation on pin 0 to produce sounds
// The Period determines the pitch, "wait" determines the length
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
}

#endif
