#pragma once

#include "touch.h"
#include "mbed.h"

namespace IoTShield {

  enum ButtonName {
    BTN_1 = KEY_1,
    BTN_UP = KEY_1,

    BTN_2 = KEY_4,
    BTN_LEFT = KEY_4,

    BTN_3 = KEY_5,
    BTN_DOT = KEY_5,
    BTN_CONFIRM = KEY_5,

    BTN_4 = KEY_2,
    BTN_RIGHT = KEY_2,

    BTN_5 = KEY_3,
    BTN_DOWN = KEY_3
  };

  class Button : public ITouchEventHandler {

    public:
      // TODO: Refactor to singleton or factory for touch ...
      Button(ButtonName name, Touch * touch);

    public:
      void pressed(Callback<void()> handler);
      void released(Callback<void()> handler);

    public:
      virtual void touch_event_occured(TouchEvent event);

    private:
      Touch * touch;
      Callback<void()> pressedCallback;
      Callback<void()> releasedCallback;
  };

};
