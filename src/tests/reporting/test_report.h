#pragma once

#include <string>
#include <cstdio>
#include <vector>
#include "test_result.h"

namespace IoTShield {
  namespace Tests {

    class TestReport {

      public:
        TestReport(std::string description) {
          this->description = description;
          numberOfFails = 0;
          numberOfSuccesses = 0;
        }

        void add(TestResult result) {
          results.push_back(result);
          if (result.was_test_successful()) {
            numberOfSuccesses++;
          } else {
            numberOfFails++;
          }
        }

        void add(TestReport report) {
          for (unsigned int i = 0; i < report.results.size(); i++) {
            this->results.push_back(report.results[i]);
          }
        }

        int number_of_fails(void) {
          return numberOfFails;
        }

        int number_of_success(void) {
          return numberOfSuccesses;
        }

        int number_of_tests(void) {
          return results.size();
        }

        std::string to_string(void) {
          std::string report = "-----------------------------------------------------\r\n";
          report += description + "\r\n\r\n";

          for (unsigned int i = 0; i < results.size(); i++) {
            report += results[i].to_string() + "\r\n";
          }

          char buffer[128];
          sprintf(buffer, "\r\nOut of %d tests run, %d were successful and %d failed",
            number_of_tests(), number_of_success(), number_of_fails());

          return report + std::string(buffer) + "\r\n-----------------------------------------------------\r\n";
        }

      private:
        std::string description;
        std::vector<TestResult> results;
        unsigned int numberOfFails;
        unsigned int numberOfSuccesses;

    };

  };
};
