#include "i2c_device.h"

namespace IoTShield {
  namespace Drivers {

    I2cDevice::I2cDevice(int address, I2C * i2cBus) {
      this->address = address;
      this->i2cBus = i2cBus;
    }

    bool I2cDevice::write(char * data, int length) {
      return (i2cBus->write(address, data, length) == 0);
    }

    bool I2cDevice::read(char * buffer, int length) {
      return (i2cBus->read(address, buffer, length) == 0);
    }

  };
};
