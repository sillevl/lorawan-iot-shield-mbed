#pragma once

#include "mbed.h"

class PirSensor
{
public: 
    enum State { MOTION, NO_MOTION };

    PirSensor(PinName pinName);
    PirSensor::State getState();

private:
    InterruptIn input;
};