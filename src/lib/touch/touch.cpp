#include "touch.h"

namespace IoTShield {

  int Touch::numberOfInstances = 0;

  Touch::Touch(int address, I2C * i2cBus)
    : qt1070(address, i2cBus) {

      initialize();
  }

  Touch::Touch(int address, I2C * i2cBus, PinName changePin)
    : qt1070(address, i2cBus, changePin, this) {

      initialize();
      setup_isr();
  }

  void Touch::initialize(void) {
    interruptEnabled = false;
    for (unsigned int i = 0; i < NUMBER_OF_KEYS; i++) {
      keyHandlers[i] = nullptr;
    }
  }

  void Touch::setup_isr(void) {
    keepServingIsr = true;
    isrSignalFlag = 0x01 << numberOfInstances++;
    isrThread.start(callback(this, &Touch::touch_event_handler));
    interruptEnabled = true;
  }

  Touch::~Touch(void) {
    if (interruptEnabled) {
      keepServingIsr = false;
      isrThread.signal_set(isrSignalFlag);
      isrThread.join();
    }
  }

  void Touch::register_event_handler(TouchKey key, ITouchEventHandler * handler) {
    if (interruptEnabled) {
      unsigned int keyIndex = get_key_index(key);
      keyHandlers[keyIndex] = handler;
    }
  }

  unsigned int Touch::get_key_index(TouchKey key) {
    static TouchKey KEY_LIST[] = { KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7 };

    for (unsigned int i = 0; i < NUMBER_OF_KEYS; i++) {
      if (KEY_LIST[i] == key) {
        return i;
      }
    }

    return -1;  // Should never be reached
  }

  void Touch::qt1070_interrupt_occured(void) {
    // Need to switch to thread, still in ISR context
    isrThread.signal_set(isrSignalFlag);
  }

  void Touch::touch_event_handler(void) {
    char previousKeyState = 0;

    while(keepServingIsr) {
      Thread::signal_wait(isrSignalFlag);
      Drivers::Qt1070::Qt1070Status qtStatus = qt1070.status();

      if (keepServingIsr && qtStatus.keyStates != previousKeyState) {
        char changedKeys = previousKeyState ^ qtStatus.keyStates;
        for (unsigned int i = 0; i < NUMBER_OF_KEYS; i++) {
          char mask = 0x01 << i;
          if ((changedKeys & mask) && keyHandlers[i] != nullptr) {
            TouchEvent event;
            event.key = (TouchKey)(changedKeys & mask);
            event.state = (TouchKeyState)((qtStatus.keyStates & mask) >> i);

            keyHandlers[i]->touch_event_occured(event);
          }
        }
      }
      previousKeyState = qtStatus.keyStates;
    }
  }

};
