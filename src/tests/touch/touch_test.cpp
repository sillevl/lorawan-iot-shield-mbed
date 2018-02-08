#include "touch_test.h"
#include "lib/touch/keypad.h"

namespace IoTShield {
  namespace Tests {

    const TouchKey TouchTest::pads[NUMBER_OF_BUTTONS] = {
      KEY_1, KEY_4, KEY_5, KEY_2, KEY_3
    };

    TouchTest::TouchTest(Serial &pc)
      : terminal(pc) {
    }

    TestReport TouchTest::run_all_tests(void) {
      TestReport results("Test suite to check the Touch control");
      results.add(are_all_pads_touchable());
      return results;
    }

    TestResult TouchTest::are_all_pads_touchable(void) {
      I2C i2c(A4, A5);
      IoTShield::Touch touch(0x1B<<1, &i2c, PTB3);

      numberOfKeysLeftToDetect = NUMBER_OF_BUTTONS;
      for (unsigned int i = 0; i < NUMBER_OF_BUTTONS; i++) {
        touch.register_event_handler(pads[i], this);
        hasPadBeenTouched[i] = false;
      }

      bool keepWaiting = true;
      printf("Please touch all pads. Press any key in terminal to abort test!\r\n");
      while (keepWaiting) {
        if(terminal.readable() || numberOfKeysLeftToDetect == 0) {
          keepWaiting = false;
          if (terminal.readable()) {
            terminal.getc();  // Need to read the char to clean the buffer
          }
        }
        print_touchable_pads_progress();
        wait_ms(10);  // Get rid of the flickering
      }
      printf("\r\n");

      TestResult result("Test if all pads are touchable");
      result.set_result(numberOfKeysLeftToDetect == 0);
      return result;
    }

    void TouchTest::print_touchable_pads_progress(void) {
      for (unsigned int i = 0; i < NUMBER_OF_BUTTONS; i++) {
        terminal.printf("| %s", (hasPadBeenTouched[i] ? "X ": "? "));
      }
      printf("|\r");
      fflush(stdout);
    }

    void TouchTest::touch_event_occured(TouchEvent event) {
      for (unsigned int i = 0; i < NUMBER_OF_BUTTONS; i++) {
        if (pads[i] == event.key && !hasPadBeenTouched[i] && event.state == PRESSED) {
          hasPadBeenTouched[i] = true;
          numberOfKeysLeftToDetect--;
        }
      }
    }

  };
};
