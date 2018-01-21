#include "build_options.h"

#ifdef TEST_EXAMPLE

#include "mbed.h"
#include "tests/board_test.h"

DigitalOut aliveLed(LED1);
Serial pc(USBTX, USBRX);

int main() {
  pc.baud(115200);
  printf("Booting LoRaWAN IoT Shield in Test Mode ...\r\n");

  IoTShield::Tests::BoardTest boardTest(pc);
  boardTest.run_interactive_tests();

  while (true) {
    Thread::wait(1000);
    aliveLed = !aliveLed;
  }
}

#endif
