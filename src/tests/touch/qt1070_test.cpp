#include "qt1070_test.h"

namespace IoTShield {
  namespace Tests {

    bool Qt1070Test::is_i2c_available(void) {
      I2C i2c(A4, A5);
      IoTShield::Drivers::Qt1070 qt1070(0x1B<<1, &i2c);

      return qt1070.chip_id() == DEFAULT_CHIP_ID;
    }
  };
};
