#include "qt1070.h"
#include "mbed.h"

namespace IoTShield {
  namespace Drivers {

    Qt1070::Qt1070(int address, I2C * i2cBus)
      : I2cDevice(address, i2cBus) {

        reset();
    }

    Qt1070::Qt1070(int address, I2C * i2cBus, PinName changePin, IQt1070InterruptHandler * handler)
      : Qt1070(address, i2cBus) {

        setup_isr(changePin, handler);
    }

    void Qt1070::setup_isr(PinName changePin, IQt1070InterruptHandler * handler) {
      status();   // Make sure all status bytes are read and interrupt is cleared

      this->interruptHandler = handler;
      changeInterrupt = new InterruptIn(changePin);
      changeInterrupt->mode(PullUp);
      changeInterrupt->fall(callback(this, &Qt1070::internal_isr));
    }

    char Qt1070::chip_id(void) {
      return read_register(CHIP_ID_REG);
    }

    char Qt1070::key_states(void) {
      return status().keyStates;
    }

    void Qt1070::reset(void) {
      write_register(RESET_REG, 0xFF);
      wait_ms(300);
    }

    void Qt1070::calibrate(void) {
      write_register(CALIBRATE_REG, 0xFF);
    }

    char Qt1070::detection_status(void) {
      return status().detectionStatus;
    }

    Qt1070::Qt1070Status Qt1070::status(void) {
      char buffer[2];
      set_register_address(DETECTION_STATUS_REG);
      read(buffer, sizeof(buffer));

      Qt1070Status qtStatus;
      qtStatus.detectionStatus = buffer[0];
      qtStatus.keyStates = buffer[1];

      return qtStatus;
    }

    void Qt1070::internal_isr(void) {
      if (interruptHandler) {
        interruptHandler->qt1070_interrupt_occured();
      }
    }

  };
};
