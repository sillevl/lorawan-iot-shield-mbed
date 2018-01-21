#pragma once

#include <vector>
#include "test_report.h"

namespace IoTShield {
  namespace Tests {

    class ITest {

      public:
        TestReport run_all_tests(void);
    };

  };
};
