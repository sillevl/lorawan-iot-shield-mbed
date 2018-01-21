#pragma once

#include "lib/touch/driver/qt1070.h"
#include "tests/i_test.h"

namespace IoTShield {
  namespace Tests {

    class Qt1070Test : public ITest {

      public:
        TestReport run_all_tests(void);

      private:
        TestResult is_i2c_available(void);

      private:
        static const int DEFAULT_CHIP_ID = 0x2E;
    };

  };
};
