#include <Arduino.h>
#include "WiFi.h"
#include "AsyncUDP.h"
#include "WiFi.h"

#include <Drone.h>

const int X_JOY_PIN = 34;
const int Y_JOY_PIN = 35;
const int BUTTON_PIN = 27;
const int LED_PIN = 25;
const uint8_t LCD_ADDR = 0x27;
int buttonState = 0;

const char *ssid = "wifi ssid";
const char *password = "wifi password";
Drone drone = Drone(X_JOY_PIN, Y_JOY_PIN, BUTTON_PIN, LED_PIN, LCD_ADDR); // Instantiate object

void SetupWifi()
{
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    if (WiFi.waitForConnectResult() != WL_CONNECTED)
    {
        Serial.println("WiFi Failed");
    }
    else
    {
        Serial.println("WiFi Connected...");
    }
}

void setup()
{
    Serial.begin(9600);
    SetupWifi();

    buttonState = 0;
}


void loop()
{
    delay(1000);
    buttonState = digitalRead(BUTTON_PIN);
    Serial.print("buttonState: ");
    Serial.println(buttonState);

    if (buttonState == 0)
    {
        drone.ChangeStatus();
    }
   
    if (drone.droneIsOn())
    {
        Serial.println("droneIsOn");

        std::pair<int, int> xy = drone.joystick->getJoystickValues();
        drone.Move(xy);
    }
}
