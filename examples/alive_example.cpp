#include "build_options.h"
#ifdef ALIVE_EXAMPLE

#include "mbed.h"

DigitalOut aliveLed(LED1);
Serial pc(USBTX, USBRX);

int main() {
  pc.baud(115200);
  printf("Booting LoRaWAN IoT Shield ...\r\n");

  while (true) {
    wait(1);
    aliveLed = !aliveLed;
  }
}

#endif
