#include <Arduino.h>


class Led {       // The class
  public:
    int pinNumber;
    bool state=false;             // Access specifier
    Led(int pinNumber)
    {
        this->pinNumber = pinNumber;
        pinMode(this->pinNumber, OUTPUT);
    }
    void on()
    {
        digitalWrite(this->pinNumber, HIGH);
        this->state = true;
    }

    void off()
    {
        digitalWrite(this->pinNumber, LOW);
        this->state = false;
    }

    String status()
    {
        String s;
        s += "Led on pin ";
        s += this->pinNumber;
        s += " is ";
        if (this->state)
        {
            s+= "on";
        }else
        {
            s+= "off";
        }

        return s;
    }
};