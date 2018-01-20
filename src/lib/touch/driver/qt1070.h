#pragma once

#include "lib/i2c/i2c_device.h"
#include "qt1070_events.h"
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
        Qt1070(int address, I2C * i2cBus, PinName changePin);
        ~Qt1070(void);

      public:
        char chip_id(void);
        void reset(void);
        void calibrate(void);
        char key_states(void);
        char detection_status(void);
        Qt1070Status status(void);

      public:
        void register_event_handler(Qt1070Key key, Qt1070ChangeHandler handler);

      private:
        unsigned int get_key_index(Qt1070Key key);

        char read_register(Qt1070Register reg);
        void write_register(Qt1070Register reg, char value);
        void set_register_address(Qt1070Register reg);

      private:
        static const unsigned int MS_DELAY_TRANSACTION = 1;
        static const unsigned int NUMBER_OF_KEYS = 7;

      private:
        Qt1070ChangeHandler keyHandlers[NUMBER_OF_KEYS];

      private:
        // Threading
        bool interruptEnabled;
        static int numberOfInstances;
        int isrSignalFlag;
        InterruptIn * changeInterrupt;
        Thread isrThread;
        bool keepServingIsr;

        void setup_isr(PinName changePin);
        void change_isr(void);
        void change_isr_thread_handler(void);
    };

  };
};
