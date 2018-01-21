#pragma once

#include "mbed.h"

namespace IoTShield {
  namespace Drivers {

    class I2cDevice {

      private:
        int address;
        I2C * i2cBus;

      public:
        I2cDevice(int address, I2C * i2cBus);

      protected:
        bool write(char * data, int length);
        bool read(char * buffer, int length);

        char read_register(char reg);
        void write_register(char reg, char value);
        void set_register_address(char reg);

      private:
        static const unsigned int MS_DELAY_TRANSACTION = 1;
    };

  };
};
