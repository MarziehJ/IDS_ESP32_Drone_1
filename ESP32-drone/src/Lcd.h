#ifndef LCD_h
#define LCD_h


#include "Arduino.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

class Lcd
{
public:
  Lcd(uint8_t lcd_addr)
  {
    lcd = new LiquidCrystal_I2C(lcd_addr, 20, 2);
    this->lcd->init(); // initialize the lcd
    this->lcd->backlight();
    this->lcd->setCursor(1,0);
    this->lcd->print("Display Commands...");
  };

  void WriteMessage(String msg)
  {
    Serial.print("LCD message: ");
    Serial.println(msg);
    this->lcd->init(); // initialize the lcd
    this->lcd->backlight();
    this->lcd->setCursor(1,0);
    this->lcd->print("Command: ");
    this->lcd->setCursor(1,1);
    this->lcd->print(msg);
    delay(2000);
  }

private:
  LiquidCrystal_I2C *lcd;
};

#endif