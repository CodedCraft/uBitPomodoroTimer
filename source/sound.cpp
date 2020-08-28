#include "MicroBit.h"
MicroBit uBit;

int main()
{
    uBit.init();
    uBit.io.P0.setAnalogValue(200);
    uBit.io.P0.setAnalogPeriodUs(1800);
    while (1)
        uBit.sleep(10000);
}