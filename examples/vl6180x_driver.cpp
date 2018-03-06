#include "mbed.h"
#include "iot-shield.h"

Display lcd;
I2C i2c(A4, A5);
VL6180x sensor(i2c);

int main()
{
    sensor.initialize();
    sensor.startContinuousOperation();
    // sensor.printIdentification();
    while(true) {   // this is the third thread
        lcd.cls();
        lcd.locate(0,0);
        lcd.printf("Temperature : %.2f mm", sensor.getDistance());
        lcd.locate(0,10);
        lcd.printf("Ambient light : %.2f lux", sensor.getAmbientLight());
        wait(1.0);
    }
}
