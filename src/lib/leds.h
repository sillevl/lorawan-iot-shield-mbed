#pragma once
#include "TLC59116.h"
#include "Color.h"

class Leds
{
public:
    Leds(I2C& i2c);

    void off();
    void setBrightness(float brightness);
    void setColor(int led, Color* Color);
    void setColor(int led, int color);
    void setAll(int color);
    void setAll(Color* color);
    void setAll(int* colors);

protected:
    TLC59116 ledDriver;
    static const int I2C_ADDRESS = 0xC0;

    void setLed(int startChannel, Color* color);
};