#pragma once

#include <string>
#include <cstdio>

namespace IoTShield {
  namespace Tests {

    class TestReport {
      private:
        int numberOfTests;
        int numberOfSuccess;
        int numberOfFails;

      public:
        TestReport(void) {
          numberOfTests = 0;
          numberOfSuccess = 0;
          numberOfFails = 0;
        }

        void add(bool result) {
          numberOfTests++;
          if (result) {
            numberOfSuccess++;
          } else {
            numberOfFails++;
          }
        }

        std::string to_string(void) {
          char buffer[128];
          sprintf(buffer, "Out of %d tests run, %d were successful and %d failed",
            numberOfTests, numberOfSuccess, numberOfFails);

          return std::string(buffer);
        }

    };

  };
};
