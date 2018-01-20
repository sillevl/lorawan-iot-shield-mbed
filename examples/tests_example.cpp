#include "build_options.h"
#ifdef COMPILE_TEST_EXAMPLE

#include "mbed.h"
#include "tests/board_test.h"

DigitalOut aliveLed(LED1);
Serial pc(USBTX, USBRX);

int main() {
  pc.baud(115200);
  printf("Booting LoRaWAN IoT Shield in Test Mode ...\r\n");

  IoTShield::Tests::BoardTest boardTest;
  boardTest.run_interactive_tests();

  while (true) {
    wait(1);
    aliveLed = !aliveLed;
  }
}

#endif
