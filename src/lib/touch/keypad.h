#pragma once

#include "button.h"
#include "mbed.h"

namespace IoTShield {

  class Keypad {

    public:   // TODO: Refactor so we do not need the touch
      Keypad(Touch * touch);
      virtual ~Keypad(void);

    public:
      void pressed(ButtonName buttonName, Callback<void()> handler);
      void released(ButtonName buttonName, Callback<void()> handler);

    private:
      Button* get_button_by_name(ButtonName name);

    private:
      static const unsigned int NUMBER_OF_BUTTONS = 5;
      static const ButtonName availableButtons[NUMBER_OF_BUTTONS];

      Button * buttons[NUMBER_OF_BUTTONS];
  };

};
