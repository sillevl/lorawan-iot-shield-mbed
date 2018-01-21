#pragma once

#include "lib/touch/driver/qt1070.h"

namespace IoTShield {
  namespace Tests {

    class Qt1070Test {

      public:
        bool is_i2c_available(void);

      private:
        static const int DEFAULT_CHIP_ID = 0x2E;
    };

  };
};
