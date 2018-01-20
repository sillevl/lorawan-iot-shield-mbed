#pragma once

namespace IoTShield {

    enum TouchKey {
      KEY_1 = 0x01,
      KEY_2 = 0x02,
      KEY_3 = 0x04,
      KEY_4 = 0x08,
      KEY_5 = 0x10,
      KEY_6 = 0x20,
      KEY_7 = 0x40
    };

    enum TouchKeyState {
      RELEASED = 0x00,
      PRESSED = 0x01
    };

    struct TouchEvent {
      TouchKey key;
      TouchKeyState state;
    };

};
