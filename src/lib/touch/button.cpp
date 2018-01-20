#include "button.h"

namespace IoTShield {

  Button::Button(ButtonName name, Touch * touch)
    : releasedCallback(nullptr), pressedCallback(nullptr) {

      this->touch = touch;
      this->touch->register_event_handler((TouchKey)name, this);
  }

  void Button::pressed(Callback<void()> handler) {
    if (handler) {
      pressedCallback = handler;
    } else {
      pressedCallback = nullptr;
    }
  }

  void Button::released(Callback<void()> handler) {
    if (handler) {
      releasedCallback = handler;
    } else {
      releasedCallback = nullptr;
    }
  }

  void Button::touch_event_occured(TouchEvent event) {
    if (event.state == RELEASED && releasedCallback) {
      releasedCallback();
    } else if (event.state == PRESSED && pressedCallback) {
      pressedCallback();
    }
  }

};
