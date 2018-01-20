#include "build_options.h"

#ifdef TOUCH_EXAMPLE

#include "mbed.h"
#include "lib/touch/touch.h"

DigitalOut aliveLed(LED1);
Serial pc(USBTX, USBRX);

class Foo : public IoTShield::ITouchEventHandler {
  void touch_event_occured(IoTShield::TouchEvent event) {
    printf("Key event\r\n");
  }
};

int main() {
  pc.baud(115200);
  printf("Booting LoRaWAN IoT Shield ...\r\n");

  I2C i2c(A4, A5);
  Foo handler;
  IoTShield::Touch touch(0x1B<<1, &i2c, PTB3);

  touch.register_event_handler(IoTShield::KEY_1, &handler);

  while (true) {
    Thread::wait(1000);
    aliveLed = !aliveLed;
  }
}

#endif
