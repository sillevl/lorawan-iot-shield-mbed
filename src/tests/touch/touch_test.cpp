#include "touch_test.h"
#include "hal/touch/touch.h"

namespace IoTShield {
  namespace Tests {

    TouchTest::TouchTest(Drivers::Qt1070 * qt1070) {
      this->qt1070 = qt1070;
    }

    bool TouchTest::is_i2c_available(void) {
      return this->qt1070->chip_id() == DEFAULT_CHIP_ID;
    }
  };
};
