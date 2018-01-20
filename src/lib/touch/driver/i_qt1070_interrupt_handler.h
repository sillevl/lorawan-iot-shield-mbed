#pragma once

namespace IoTShield {
  namespace Drivers {

    class IQt1070InterruptHandler {

      public:
        virtual void qt1070_interrupt_occured(void);

    };

  };
};
