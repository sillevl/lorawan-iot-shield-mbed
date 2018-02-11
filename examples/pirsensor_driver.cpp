#include "mbed.h"
#include "iot-shield.h"
 
I2C i2c(A4, A5);

Leds leds(i2c);
PirSensor pir(D8);
 
int main()
{
    leds.setBrightness(0.50);

    while(true){
        if(pir.getState() == PirSensor::MOTION){
            leds.setColor(0, Color::RED);
        } else {
            leds.setColor(0, Color::BLACK);
        }
    }
}
 