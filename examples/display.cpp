#include "mbed.h"
#include "iot-shield.h"
 
Display lcd;
 
int main()
{
    int j=0;
    lcd.cls();
    lcd.locate(0,3);
    lcd.printf("LoRaWAN IoT shield!");
 
    while(true) {   // this is the third thread
        lcd.locate(0,15);
        lcd.printf("Counting : %d",j++);
        wait(1.0);
    }
}
 