#include "iot-shield.h"



IoTShield::IoTShield():pir(D8)
{
    i2c = new I2C(A4, A5);
}

float IoTShield::temperature()
{
    return 12.3;
}

PirSensor::State IoTShield::getMotionState()
{
    return pir.getState();
}