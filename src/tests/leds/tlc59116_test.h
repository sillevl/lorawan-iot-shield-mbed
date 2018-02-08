#pragma once

#include "lib/leds/driver/tlc59116.h"
#include "tests/i_test.h"

namespace IoTShield {
  namespace Tests {

    class TLC59116Test : public ITest {

      public:
        TLC59116Test(Serial &pc);

      public:
        TestReport run_all_tests(void);

      private:
        TestResult are_all_channels_addressable(void);

      private:
        Serial &terminal;
        const static int NUMBER_OF_RGB_LEDS = 5;
    };

  };
};
