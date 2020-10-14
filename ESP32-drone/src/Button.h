
#ifndef Button_h
#define Button_h

#include "Arduino.h"

class Button {
public:
  Button(int buttonPin) {
    this->buttonPin = buttonPin;
    pinMode(this->buttonPin, INPUT_PULLUP);
  }

  bool isPressed() { return digitalRead(buttonPin) == 0; }

private:
  int buttonPin = 0;
};

#endif