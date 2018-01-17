#pragma once

#include "qt1070_register.h"
#include "../i2c/i2c_device.h"

namespace IoTShield {
  namespace Drivers {

    class Qt1070 {

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
        I2cDevice i2cDevice;

      private:
        static const unsigned int MS_DELAY_TRANSACTION = 1000;
    };

  };
};
