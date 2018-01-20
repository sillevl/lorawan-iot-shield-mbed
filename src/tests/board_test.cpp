#include "board_test.h"
#include "touch/touch_test.h"

namespace IoTShield {
  namespace Tests {

    BoardTest::BoardTest(void) { }

    void BoardTest::run_interactive_tests(void) {
      printf("Running interactive tests\r\n");

      TestReport results;
      run_interactive_touch_tests(&results);

      printf("%s\r\n", results.to_string().c_str());
    }

    void BoardTest::run_interactive_touch_tests(TestReport * report) {
      I2C i2c(A4, A5);
      IoTShield::Drivers::Qt1070 qt1070(0x1B<<1, &i2c);
      TouchTest touchtest(&qt1070);

      bool i2cResult = touchtest.is_i2c_available();
      report->add(i2cResult);
      printf("[%s] QT1070 I2C test\r\n", (i2cResult ? "V" : "X"));
    }

  };
};
