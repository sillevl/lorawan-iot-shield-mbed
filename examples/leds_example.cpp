#include "build_options.h"

#ifdef LEDS_EXAMPLE

#include "mbed.h"
#include "lib/leds/driver/tlc59116.h"

DigitalOut aliveLed(LED1);
Serial pc(USBTX, USBRX);

int main() {
  pc.baud(115200);
  printf("Booting LoRaWAN IoT Shield ...\r\n");

  I2C i2c(A4, A5);
  IoTShield::Drivers::TLC59116 tlc(0xC0, &i2c);
  tlc.set_all(0.3);
  wait(1);
  tlc.all_off();
  wait(1);
  tlc.set_channel(0, 0.5);
  tlc.set_channel(4, 0.5);
  tlc.set_channel(8, 0.5);
  wait(1);

  while (true) {
    Thread::wait(1000);
    aliveLed = !aliveLed;
  }
}

#endif
