#include "build_options.h"

#ifdef KEYPAD_EXAMPLE

#include "mbed.h"
#include "lib/touch/keypad.h"

DigitalOut aliveLed(LED1);
Serial pc(USBTX, USBRX);

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

  IoTShield::Keypad control(&touch);
  Foo foo_up(1);
  control.released(IoTShield::BTN_UP, callback(&foo_up, &Foo::released));
  Foo foo_left(2);
  control.released(IoTShield::BTN_LEFT, callback(&foo_left, &Foo::released));
  Foo foo_ok(3);
  control.released(IoTShield::BTN_CONFIRM, callback(&foo_ok, &Foo::released));

  while (true) {
    Thread::wait(1000);
    aliveLed = !aliveLed;
  }
}

#endif
