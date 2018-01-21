#include "keypad.h"

namespace IoTShield {

  const ButtonName Keypad::availableButtons[] = {
    BTN_UP, BTN_LEFT, BTN_CONFIRM, BTN_RIGHT, BTN_DOWN
  };

  Keypad::Keypad(Touch * touch) {
    for (unsigned int i = 0; i < NUMBER_OF_BUTTONS; i++) {
      buttons[i] = new Button(availableButtons[i], touch);
    }
  }

  Keypad::~Keypad(void) {
    for (unsigned int i = 0; i < NUMBER_OF_BUTTONS; i++) {
      buttons[i]->pressed(nullptr);
      buttons[i]->released(nullptr);
      delete buttons[i];
    }
  }

  void Keypad::pressed(ButtonName buttonName, Callback<void()> handler) {
    get_button_by_name(buttonName)->pressed(handler);
  }

  void Keypad::released(ButtonName buttonName, Callback<void()> handler) {
    get_button_by_name(buttonName)->released(handler);
  }

  Button* Keypad::get_button_by_name(ButtonName name) {
    for (unsigned int i = 0; i < NUMBER_OF_BUTTONS; i++) {
      if (name == availableButtons[i]) {
        return buttons[i];
      }
    }
    return nullptr;
  }

};
