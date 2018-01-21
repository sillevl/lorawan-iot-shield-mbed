#pragma once

#include "lib/touch/touch.h"
#include "lib/touch/button.h"

namespace IoTShield {
  namespace Tests {

    class TouchTest : public ITouchEventHandler {

      public:
        TouchTest(Serial &pc);

      public:
        bool are_all_pads_touchable(void);

      public:
        virtual void touch_event_occured(TouchEvent event);

      private:
        void print_touchable_pads_progress(void);

      private:
        static const unsigned int NUMBER_OF_BUTTONS = 5;
        static const TouchKey pads[NUMBER_OF_BUTTONS];

      private:
        Serial &terminal;
        bool hasPadBeenTouched[NUMBER_OF_BUTTONS];
        int numberOfKeysLeftToDetect;

    };

  };
};
