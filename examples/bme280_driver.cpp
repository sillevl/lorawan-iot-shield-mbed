#include "mbed.h"
#include "iot-shield.h"
 
Display lcd;
BME280 sensor(A4, A5);
 
int main()
{
    while(true) {   // this is the third thread
        lcd.cls();
        lcd.locate(0,0);
        lcd.printf("Temperature : %.2f °C", sensor.getTemperature() - 273.15);
        lcd.locate(0,10);
        lcd.printf("Humidity : %.2f%%", sensor.getHumidity());
        lcd.locate(0,20);
        lcd.printf("Pressure : %.2fhPa", sensor.getPressure());
        wait(1.0);
    }
}
 