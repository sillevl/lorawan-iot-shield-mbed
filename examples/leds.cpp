#include "mbed.h"
#include "iot-shield.h"
 
I2C i2c(A4, A5);

Leds leds(i2c);

 
int main()
{
    leds.setBrightness(0.50);

    while(true){
        leds.setAll(Color::BLACK);
        wait(0.5);
        leds.setAll(Color::RED);
        wait(0.5);
        leds.setAll(Color::GREEN);
        wait(0.5);
        leds.setAll(Color::BLUE);
        wait(0.5);
    }
}
 