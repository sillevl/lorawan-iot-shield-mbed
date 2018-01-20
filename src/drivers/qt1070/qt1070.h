#pragma once

#include "drivers/i2c/i2c_device.h"

namespace IoTShield {
  namespace Drivers {

    class Qt1070 : public I2cDevice {

      enum Qt1070Register {
        CHIP_ID_REG = 0,
        DETECTION_STATUS_REG = 2,
        KEY_STATE_REG = 3,
        CALIBRATE_REG = 56,
        RESET_REG = 57
      };

      public:
        Qt1070(int address, I2C * i2cBus);

      public:
        char chip_id(void);
        char key_state(void);
        void reset(void);
        void calibrate(void);
        char detection_status(void);

      private:
        char read_register(Qt1070Register reg);
        void write_register(Qt1070Register reg, char value);
        void set_register_address(Qt1070Register reg);

      private:
        static const unsigned int MS_DELAY_TRANSACTION = 1;
    };

  };
};
