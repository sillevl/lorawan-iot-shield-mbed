#include "tlc59116_test.h"
#include "mbed.h"

namespace IoTShield {
  namespace Tests {

    TLC59116Test::TLC59116Test(Serial &pc)
      : terminal(pc) {
    }

    TestReport TLC59116Test::run_all_tests(void) {
      TestReport results("Test suite to check the TLC59116");
      results.add(are_all_channels_addressable());
      return results;
    }

    TestResult TLC59116Test::are_all_channels_addressable(void) {
      I2C i2c(A4, A5);
      IoTShield::Drivers::TLC59116 tlc(0xC0, &i2c);

      printf("Please keep an eye on the LEDs?\r\n");
      wait_ms(2000);
      for (unsigned int c = 0; c < 3; c++) {
        for (unsigned int i = 0; i < NUMBER_OF_RGB_LEDS; i++) {
          tlc.set_channel(3*i+c, 0.10);
        }
        wait_ms(2000);
        tlc.all_off();
      }

      printf("Were all three colors (RGB) displayed for each LED at about 10%% brightness? [y/n]: ");
      char answer = terminal.getc();
      printf("\r\n");

      TestResult result("Test if all channels of TLC59116 are addressable");
      result.set_result(answer == 'y');

      return result;
    }
  };
};
