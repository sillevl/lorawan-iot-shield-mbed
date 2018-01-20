#pragma once

#include "lib/touch/driver/qt1070.h"

namespace IoTShield {
  namespace Tests {

    class TouchTest {

      public:
        TouchTest(Drivers::Qt1070 * qt1070);

      public:
        bool is_i2c_available(void);

      private:
        Drivers::Qt1070 * qt1070;

      private:
        static const int DEFAULT_CHIP_ID = 0x2E;
        static const int MAX_SECONDS_FOR_PADS_TEST = 60;
    };

  };
};
