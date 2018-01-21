#pragma once

#include "lib/touch/touch.h"
#include "lib/touch/button.h"
#include "tests/i_test.h"

namespace IoTShield {
  namespace Tests {

    class TouchTest : public ITouchEventHandler, public ITest {

      public:
        TouchTest(Serial &pc);

      public:
        TestReport run_all_tests(void);

      private:
        TestResult are_all_pads_touchable(void);

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
