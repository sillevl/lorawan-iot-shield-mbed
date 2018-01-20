#pragma once

#include "lib/i2c/i2c_device.h"
#include "i_qt1070_interrupt_handler.h"
#include "mbed.h"

namespace IoTShield {
  namespace Drivers {

    class Qt1070 : public I2cDevice {

      public:
        struct Qt1070Status {
            char detectionStatus;
            char keyStates;
        };

      private:
        enum Qt1070Register {
          CHIP_ID_REG = 0,
          DETECTION_STATUS_REG = 2,
          KEY_STATE_REG = 3,
          CALIBRATE_REG = 56,
          RESET_REG = 57
        };

      public:
        Qt1070(int address, I2C * i2cBus);
        Qt1070(int address, I2C * i2cBus, PinName changePin, IQt1070InterruptHandler * handler);

      public:
        char chip_id(void);
        void reset(void);
        void calibrate(void);
        char key_states(void);
        char detection_status(void);
        Qt1070Status status(void);

      private:
        char read_register(Qt1070Register reg);
        void write_register(Qt1070Register reg, char value);
        void set_register_address(Qt1070Register reg);

      private:
        static const unsigned int MS_DELAY_TRANSACTION = 1;

      private:
        // Interrupt
        IQt1070InterruptHandler * interruptHandler;
        InterruptIn * changeInterrupt;

        void setup_isr(PinName changePin, IQt1070InterruptHandler * handler);
        void internal_isr(void);
    };

  };
};
