#include "tlc59116.h"

namespace IoTShield {
  namespace Drivers {

    TLC59116::TLC59116(int address, I2C * i2cBus)
      : I2cDevice(address, i2cBus) {

        reset();
        enable_brightness_and_group_dimming();
        wait_ms(MS_DELAY_TRANSACTION);
        enable();
        wait_ms(MS_DELAY_TRANSACTION);
        all_off();
    }

    void TLC59116::reset(void) {
      // can we reset the tlc ?
    }

    void TLC59116::enable_brightness_and_group_dimming(void) {
      char reg = get_auto_increment_register_address(REG_LEDOUT0);
      char buffer[] = { reg, 0xFF, 0xFF, 0xFF, 0xFF };
      write(buffer, sizeof(buffer));
    }

    void TLC59116::enable(void) {
      char mode = read_register(REG_MODE_1);
      mode &= (~0x01 << 4);
      wait_ms(MS_DELAY_TRANSACTION);
      write_register(REG_MODE_1, mode);
    }

    void TLC59116::set_all(float brightness) {
      // Code below alone does not work. I think it is because it is superposed on
      // the values already in the individual brightness registers
      //write_register(REG_GRPPWM, brightness * 255.0);

      char reg = get_auto_increment_register_address(REG_LED_0);
      char buffer[NUMBER_OF_CHANNELS+1];
      buffer[0] = reg;
      for (unsigned int i = 0; i < NUMBER_OF_CHANNELS; i++) {
        buffer[i+1] = brightness*255.0;
      }
      write(buffer, sizeof(buffer));
    }

    void TLC59116::all_off(void) {
      set_all(0);
    }

    void TLC59116::set_channel(int index, float brightness) {
      if (index < NUMBER_OF_CHANNELS) {
        write_register(REG_LED_0+index, brightness * 255.0);
      }
    }

    char TLC59116::get_auto_increment_register_address(TLC59116Register reg) {
      return reg | AUTO_INCREMENT_REGISTER_MASK;
    }

  };
};
