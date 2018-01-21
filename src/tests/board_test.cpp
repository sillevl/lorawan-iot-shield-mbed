#include "board_test.h"
#include "touch/qt1070_test.h"
#include "touch/touch_test.h"

namespace IoTShield {
  namespace Tests {

    BoardTest::BoardTest(Serial &pc)
      : terminal(pc) {
    }

    void BoardTest::run_interactive_tests(void) {
      printf("Running interactive tests\r\n");

      TestReport results;
      run_interactive_touch_tests(&results);

      printf("%s\r\n", results.to_string().c_str());
    }

    void BoardTest::run_interactive_touch_tests(TestReport * report) {
      Qt1070Test qt1070Test;
      bool i2cResult = qt1070Test.is_i2c_available();
      report->add(i2cResult);
      printf("[%s] QT1070 I2C test\r\n", (i2cResult ? "V" : "X"));

      TouchTest touchTest(terminal);
      bool touchResult = touchTest.are_all_pads_touchable();
      report->add(touchResult);
      printf("[%s] All pads touchable test\r\n", (touchResult ? "V" : "X"));
    }

  };
};
