#pragma once

#include "lib/i2c/i2c_device.h"
#include "mbed.h"

namespace IoTShield {
  namespace Drivers {

    class TLC59116 : public I2cDevice {

      private:
        enum TLC59116Register {
          REG_MODE_1 = 0x00,
          REG_LED_0 = 0x02,
          REG_GRPPWM = 0x12,
          REG_LEDOUT0 = 0x14,
          REG_ALLCALL = 0x1B
        };

      public:
        TLC59116(int address, I2C * i2cBus);

      public:
        void reset(void);
        void set_all(float brightness);
        void all_off(void);
        void set_channel(int index, float brightness);

      private:
        void enable(void);
        void enable_brightness_and_group_dimming(void);
        char get_auto_increment_register_address(TLC59116Register reg);

      private:
        static const char AUTO_INCREMENT_REGISTER_MASK = 0x80;
        static const char NUMBER_OF_CHANNELS = 16;

    };

  };
};
