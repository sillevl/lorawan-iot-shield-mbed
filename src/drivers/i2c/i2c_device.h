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
    };

  };
};
