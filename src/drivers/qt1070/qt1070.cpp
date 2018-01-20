#include "qt1070.h"

namespace IoTShield {
  namespace Drivers {

    Qt1070::Qt1070(int address, I2C * i2cBus)
      : I2cDevice(address, i2cBus) {
    }

    char Qt1070::chip_id(void) {
      return read_register(CHIP_ID_REG);
    }

    char Qt1070::key_state(void) {
      return read_register(KEY_STATE_REG);
    }

    void Qt1070::reset(void) {
      write_register(RESET_REG, 0xFF);
    }

    void Qt1070::calibrate(void) {
      write_register(CALIBRATE_REG, 0xFF);
    }

    char Qt1070::detection_status(void) {
      return read_register(DETECTION_STATUS_REG);
    }

    char Qt1070::read_register(Qt1070Register reg) {
      char buffer[1];
      set_register_address(reg);
      wait_ms(MS_DELAY_TRANSACTION);
      read(buffer, sizeof(buffer));
      wait_ms(MS_DELAY_TRANSACTION);
      return buffer[0];
    }

    void Qt1070::write_register(Qt1070Register reg, char value) {
      char buffer[2];
      buffer[0] = reg;
      buffer[1] = value;
      write(buffer, sizeof(buffer));
    }

    void Qt1070::set_register_address(Qt1070Register reg) {
      char buffer[1];
      buffer[0] = reg;
      write(buffer, sizeof(buffer));
    }

  };
};
