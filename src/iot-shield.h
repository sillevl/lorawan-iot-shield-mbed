#pragma once

#include "mbed.h"
#include "pirsensor.h"

class IoTShield
{
public:
    IoTShield();
    float temperature();
    PirSensor::State getMotionState();

protected:
    I2C* i2c;
    PirSensor pir;
    Leds leds;
};