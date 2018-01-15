#include "pirsensor.h"

PirSensor::PirSensor(PinName pinName): input(pinName)
{
    input.mode(PullNone);
    //_interrupt.rise(callback(this, &Counter::increment));
}

PirSensor::State PirSensor::getState()
{
    return input.read() ? MOTION : NO_MOTION;
}