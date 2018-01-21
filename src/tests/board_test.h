#pragma once

#include "reporting/test_report.h"
#include "mbed.h"

namespace IoTShield {
  namespace Tests {

    class BoardTest {

      public:
        BoardTest(Serial &pc);

      public:
        void run_interactive_tests(void);

      private:
        void run_interactive_touch_tests(TestReport * report);

      private:
        Serial &terminal;
    };

  };
};
