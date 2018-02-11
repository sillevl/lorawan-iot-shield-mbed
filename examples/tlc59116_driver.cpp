#include "mbed.h"
#include "iot-shield.h"
 
I2C i2c(A4, A5);

TLC59116 leddriver(i2c, 0xC0);

void setLed(int index, float red, float green, float blue)
{
    leddriver.setChannel((3 * index) + 0, red);
    leddriver.setChannel((3 * index) + 1, green);
    leddriver.setChannel((3 * index) + 2, blue);
}

void allLedsOff()
{
    for(int i = 0; i < 5; i++){
        setLed(i, 0.0, 0.0, 0.0);
    }
}
 
int main()
{
    leddriver.enable();
    leddriver.setBrightness(0.50);

    allLedsOff();

    for(int i = 0; i < 15; i++){
        leddriver.setChannel(i, 0.0);
    }

    while(true){
        wait(0.5);
        for(int i = 0; i < 5; i++) {
            setLed(i, 1.0, 0.0, 0.0);
        } 
        wait(0.5);
        for(int i = 0; i < 5; i++) {
            setLed(i, 0.0, 1.0, 0.0);
        } 
        wait(0.5);
        for(int i = 0; i < 5; i++) {
            setLed(i, 0.0, 0.0, 1.0);
        } 
    }
}
 