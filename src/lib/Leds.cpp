#include "Leds.h"


Leds::Leds(I2C &i2c):ledDriver(i2c, I2C_ADDRESS)
{
    ledDriver.enable();
    setBrightness(0.50);
    setAll(Color::BLACK);
}

void Leds::setBrightness(float brightness)
{
    ledDriver.setBrightness(brightness);
}

void Leds::setLed(int startChannel, Color* color)
{
    ledDriver.setChannel(startChannel + 0, color->getRed() / 255.0);
    ledDriver.setChannel(startChannel + 1, color->getGreen() / 255.0);
    ledDriver.setChannel(startChannel + 2, color->getBlue() / 255.0);    
}

void Leds::setColor(int led, Color* color)
{
    setLed(led * 3, color);
}
 
void Leds::setColor(int led, int color)
{
    Color* _color = new Color(color);
    setColor(led, _color);
    delete _color;
}
 
void Leds::setAll(Color* color)
{
    for(int i = 0; i < 5; i++){
        setColor(i, color);
    }
}
 
void Leds::setAll(int color)
{
    Color* _color = new Color(color);
    setAll(_color);
    delete _color;
}
 
void Leds::setAll(int* colors)
{
    for(int i = 0; i < 5; i++){
        setColor(i, colors[i]);
    }
}