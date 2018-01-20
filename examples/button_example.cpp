#include "build_options.h"

#ifdef BUTTON_EXAMPLE

#include "mbed.h"
#include "lib/touch/button.h"

DigitalOut aliveLed(LED1);
Serial pc(USBTX, USBRX);

void pressed(void) {
  printf("Button was pressed\r\n");
}

class Foo {
  public:
    Foo(int btnId) {
      this->id = btnId;
    }

    void released(void) {
      printf("Button %d was released\r\n", id);
    }

  private:
    int id;
};

int main() {
  pc.baud(115200);
  printf("Booting LoRaWAN IoT Shield ...\r\n");

  // TODO: Below three lines should not be necessary
  I2C i2c(A4, A5);
  IoTShield::Touch touch(0x1B<<1, &i2c, PTB3);

  IoTShield::Button first(IoTShield::BTN_UP, &touch);
  first.pressed(&pressed);

  IoTShield::Button second(IoTShield::BTN_4, &touch);
  Foo foo(2);
  second.released(callback(&foo, &Foo::released));

  while (true) {
    Thread::wait(1000);
    aliveLed = !aliveLed;
  }
}

#endif
