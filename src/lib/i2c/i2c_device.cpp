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

    char I2cDevice::read_register(char reg) {
      char buffer[1];
      set_register_address(reg);
      wait_ms(MS_DELAY_TRANSACTION);
      read(buffer, sizeof(buffer));
      return buffer[0];
    }

    void I2cDevice::write_register(char reg, char value) {
      char buffer[2] = { reg, value };
      write(buffer, sizeof(buffer));
    }

    void I2cDevice::set_register_address(char reg) {
      char buffer[1] = { reg };
      write(buffer, sizeof(buffer));
    }

  };
};
