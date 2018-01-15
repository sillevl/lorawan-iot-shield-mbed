#include "leds.h"


Leds::Leds(I2C &i2c):ledDriver(i2c, I2C_ADDRESS)
{
    ledDriver.enable();
    ledDriver.setBrightness(0.10);
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
    led--; // zero indexed from now on
    led = led % 8;
    
    int channelMap[8] = {0, 3, 6, 0, 3, 6, 9, 9};
    int driverMap[8]  = {1, 1, 1, 2, 2, 2, 2, 1};
    
    TLC59116* driver = (driverMap[led] == 1) ? &driver1 : &driver2;
    int startChannel = channelMap[led];
        
    setLed(driver, startChannel, color);
}
 
void Leds::setColor(int led, int color)
{
    Color* _color = new Color(color);
    setColor(led, _color);
    delete _color;
}
 
void Leds::setAll(Color* color)
{
    for(int i = 0; i < 8; i++){
        setColor(i+1, color);
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
    for(int i = 0; i < 8; i++){
        setColor(i+1, colors[i]);
    }
}