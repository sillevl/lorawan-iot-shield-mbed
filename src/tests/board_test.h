#pragma once

#include "reporting/test_report.h"

namespace IoTShield {
  namespace Tests {

    class BoardTest {

      public:
        BoardTest(void);

      public:
        void run_interactive_tests(void);

      private:
        void run_interactive_touch_tests(TestReport * report);
    };

  };
};
