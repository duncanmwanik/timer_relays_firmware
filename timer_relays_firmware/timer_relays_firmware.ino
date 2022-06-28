#include <Arduino.h>
#include "timer_classes.h"


// initializing each timer
RepeatTimer relay1(25, 30000, 1200000);
RepeatTimer relay2(26, 10000, 10000);
DelayTimer relay3(27, 10000);

int button1Pin = 19; // to activate the 30s On 20 min Off timer
int button2Pin = 20; // to activate the 10s Delay and 10s Repeat timers
bool button1Pressed = false;
bool button2Pressed = false;

void setup()
{
    Serial.begin(115200);
    pinMode(button1Pin, INPUT_PULLUP);
    pinMode(button2Pin, INPUT_PULLUP);
}

void loop()
{
    if (!digitalRead(button1Pin))
    {
        button1Pressed = true;
        Serial.println("button 1 Pressed....");
    }
    if (!digitalRead(button2Pin))
    {
        button2Pressed = true;
        Serial.println("Button 2 Pressed....");
    }

    if (button1Pressed)
    {
        relay1.Update(1);
    }
    if (button2Pressed)
    {
        relay2.Update(2);
        relay3.Update(3);
    }
}