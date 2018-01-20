#include "qt1070.h"
#include "mbed.h"

namespace IoTShield {
  namespace Drivers {

    int Qt1070::numberOfInstances = 0;

    Qt1070::Qt1070(int address, I2C * i2cBus)
      : I2cDevice(address, i2cBus) {

        interruptEnabled = false;
        reset();
        for (unsigned int i = 0; i < NUMBER_OF_KEYS; i++) {
          keyHandlers[i] = nullptr;
        }
    }

    Qt1070::Qt1070(int address, I2C * i2cBus, PinName changePin)
      : Qt1070(address, i2cBus) {

        setup_isr(changePin);
    }

    Qt1070::~Qt1070(void) {
      if (interruptEnabled) {
        keepServingIsr = false;
        isrThread.signal_set(isrSignalFlag);
        isrThread.join();
      }
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

    void Qt1070::register_event_handler(Qt1070Key key, Qt1070ChangeHandler handler) {
      if (interruptEnabled) {
        unsigned int keyIndex = get_key_index(key);
        keyHandlers[keyIndex] = handler;
      }
    }

    unsigned int Qt1070::get_key_index(Qt1070Key key) {
      static Qt1070Key KEY_LIST[] = { KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7 };

      for (unsigned int i = 0; i < NUMBER_OF_KEYS; i++) {
        if (KEY_LIST[i] == key) {
          return i;
        }
      }

      return -1;  // Should never be reached
    }

    void Qt1070::setup_isr(PinName changePin) {
      status();   // Make sure all status bytes are read and interrupt is cleared

      changeInterrupt = new InterruptIn(changePin);
      changeInterrupt->mode(PullUp);
      changeInterrupt->fall(callback(this, &Qt1070::change_isr));
      keepServingIsr = true;

      isrSignalFlag = 0x01 << numberOfInstances++;
      isrThread.start(callback(this, &Qt1070::change_isr_thread_handler));
      interruptEnabled = true;
    }

    void Qt1070::change_isr(void) {
      isrThread.signal_set(isrSignalFlag);
    }

    void Qt1070::change_isr_thread_handler(void) {
      char previousKeyState = 0;

      while(keepServingIsr) {
        Thread::signal_wait(isrSignalFlag);
        Qt1070Status qtStatus = status();

        if (keepServingIsr && qtStatus.keyStates != previousKeyState) {
          char changedKeys = previousKeyState ^ qtStatus.keyStates;
          for (unsigned int i = 0; i < NUMBER_OF_KEYS; i++) {
            char mask = 0x01 << i;
            if ((changedKeys & mask) && keyHandlers[i] != nullptr) {
              Qt1070KeyEvent event;
              event.key = (Qt1070Key)(changedKeys & mask);
              event.state = (Qt1070KeyState)((qtStatus.keyStates & mask) >> i);
              (*(keyHandlers[i]))(event);
            }
          }
        }
        previousKeyState = qtStatus.keyStates;
      }
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
