
#ifndef Joystick_h
#define Joystick_h

#include "Arduino.h"


class Joystick {
public:
  Joystick(int xPin, int yPin) {
    // Assign values for potentiometers
    this->xPin = xPin;
    this->yPin = yPin;
    detectCenterPosition();

  };

  void setName(String s) { this->name = s; }

  std::pair<int, int> getJoystickValues() {
    int xVal = analogRead(this->xPin);
    int yVal = analogRead(this->yPin);
    return std::make_pair(xVal, yVal);
  }

  bool isInDeadzone() {
    int offset = 60;
    auto joystick = getJoystickValues();

    return std::abs(joystick.first - joyXCenterVal) < offset &&
           std::abs(joystick.second - joyYCenterVal) < offset;
  }


private:
  void detectCenterPosition() {
    auto joystick = getJoystickValues();
    joyXCenterVal = joystick.first;
    joyYCenterVal = joystick.second;
  };

  int xPin = 0;
  int yPin = 0;
  int buttonPin = 0;
  int joyXCenterVal = 0;
  int joyYCenterVal = 0;
  String name = "";
};

#endif