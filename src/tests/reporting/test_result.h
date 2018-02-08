#pragma once

#include <string>

namespace IoTShield {
  namespace Tests {

    class TestResult {
      private:
        bool wasTestSuccessful;
        std::string description;

      public:
        TestResult(std::string description) {
          this->description = description;
          wasTestSuccessful = false;
        }

        void test_failed(void) {
          wasTestSuccessful = false;
        }

        void test_succeeded(void) {
          wasTestSuccessful = true;
        }

        void set_result(bool wasTestSuccessful) {
          this->wasTestSuccessful = wasTestSuccessful;
        }

        bool was_test_successful(void) {
          return wasTestSuccessful;
        }

        std::string to_string(void) {
          char buffer[8];
          sprintf(buffer, "[%c] ", (wasTestSuccessful ? 'V': '!'));

          return (std::string(buffer) + description);
        }

    };

  };
};
