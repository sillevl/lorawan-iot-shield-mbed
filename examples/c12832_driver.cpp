#include "mbed.h"
#include "C12832.h"
 
C12832 lcd(D11, D13, D6, D7, D9);
 
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
 