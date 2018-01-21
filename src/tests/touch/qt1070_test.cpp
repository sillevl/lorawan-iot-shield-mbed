#include "qt1070_test.h"

namespace IoTShield {
  namespace Tests {

    TestReport Qt1070Test::run_all_tests(void) {
      TestReport results("Test suite to check the QT1070");
      results.add(is_i2c_available());
      return results;
    }

    TestResult Qt1070Test::is_i2c_available(void) {
      I2C i2c(A4, A5);
      IoTShield::Drivers::Qt1070 qt1070(0x1B<<1, &i2c);

      TestResult result("Test I2C of the QT1070");
      result.set_result(qt1070.chip_id() == DEFAULT_CHIP_ID);

      return result;
    }
  };
};
