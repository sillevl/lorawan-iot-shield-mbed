#pragma once

namespace IoTShield {
  namespace Drivers {

    enum Qt1070Register {
      CHIP_ID = 0,
      DETECTION_STATUS = 2,
      KEY_STATE = 3,
      CALIBRATE = 56,
      RESET = 57
    };

  };
};
