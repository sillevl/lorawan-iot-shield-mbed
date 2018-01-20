#pragma once

#include "driver/qt1070.h"
#include "touch_event.h"
#include "i_touch_event_handler.h"
#include "mbed.h"

namespace IoTShield {

  class Touch : public Drivers::IQt1070InterruptHandler {

    public:
      Touch(int address, I2C * i2cBus);
      Touch(int address, I2C * i2cBus, PinName changePin);
      virtual ~Touch(void);

    public:
      void register_event_handler(TouchKey key, ITouchEventHandler * handler);

    private:
      void initialize(void);
      unsigned int get_key_index(TouchKey key);

    private:
      Drivers::Qt1070 qt1070;

    private:
      static const unsigned int NUMBER_OF_KEYS = 7;

    private:
      // Threading and interrupt handling
      ITouchEventHandler * keyHandlers[NUMBER_OF_KEYS];

      bool interruptEnabled;
      static int numberOfInstances;
      int isrSignalFlag;
      InterruptIn * changeInterrupt;
      Thread isrThread;
      bool keepServingIsr;

      void setup_isr(void);
      void qt1070_interrupt_occured(void);
      void touch_event_handler(void);
  };

};
