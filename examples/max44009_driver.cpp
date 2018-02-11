#include "mbed.h"
#include "iot-shield.h"
 
Display lcd;
I2C i2c(A4, A5);
MAX44009 sensor(&i2c, 0x94);

int main()
{
    while(true) {   // this is the third thread
        lcd.cls();
        lcd.locate(0,0);
        lcd.printf("Light : %.2f lux", sensor.getLUXReading());
        wait(1.0);
    }
}
 