#include "board_test.h"
#include "touch/qt1070_test.h"
#include "touch/touch_test.h"
#include "leds/tlc59116_test.h"

namespace IoTShield {
  namespace Tests {

    BoardTest::BoardTest(Serial &pc)
      : terminal(pc) {
    }

    void BoardTest::run_interactive_tests(void) {
      printf("Running interactive tests\r\n");

      TestReport report("Testsuite to test the whole IoT Shield");
      run_touch_tests(&report);
      run_led_tests(&report);

      printf("%s\r\n", report.to_string().c_str());
    }

    void BoardTest::run_touch_tests(TestReport * totalReport) {
      Qt1070Test qt1070Test;
      TestReport qtReport = qt1070Test.run_all_tests();
      totalReport->add(qtReport);

      TouchTest touchTest(terminal);
      TestReport touchReport = touchTest.run_all_tests();
      totalReport->add(touchReport);
    }

    void BoardTest::run_led_tests(TestReport * totalReport) {
      TLC59116Test tlcTest(terminal);
      TestReport tlcReport = tlcTest.run_all_tests();
      totalReport->add(tlcReport);
    }

  };
};
