#include <Arduino.h>

class RepeatTimer
{
    // Class Member Variables
    // These are initialized at startup
    int relayPin; // the number of the relay pin
    long OnTime;  // milliseconds of on-time
    long OffTime; // milliseconds of off-time

    // These maintain the current state
    int relayState;               // relayState used to set the relay
    unsigned long previousMillis; // will store last time relay was updated

    // Constructor - creates a Flasher
    // and initializes the member variables and state
public:
    RepeatTimer(int pin, long on, long off)
    {
        relayPin = pin;
        pinMode(relayPin, OUTPUT);

        OnTime = on;
        OffTime = off;

        relayState = HIGH;
        previousMillis = 0;
    }

    void Update(int number)
    {
        // check to see if it's time to change the state of the relay
        unsigned long currentMillis = millis();

        if ((relayState == HIGH) && (currentMillis - previousMillis >= OnTime))
        {
            relayState = LOW;               // Turn it off
            previousMillis = currentMillis; // Remember the time
            digitalWrite(relayPin, relayState);
            Serial.print("Relay ");
            Serial.print(number);
            Serial.print(" : ");
            Serial.println("LOW");
        }
        else if ((relayState == LOW) && (currentMillis - previousMillis >= OffTime))
        {
            relayState = HIGH;              // turn it on
            previousMillis = currentMillis; // Remember the time
            digitalWrite(relayPin, relayState);
            Serial.print("Relay ");
            Serial.print(number);
            Serial.print(" : ");
            Serial.println("HIGH");
        }
    }
};

class DelayTimer
{
    // Class Member Variables
    // These are initialized at startup
    int relayPin;   // the number of the relay pin
    long delayTime; // milliseconds of delay time

    // These maintain the current state
    int relayState;
    bool triggered;               // relayState used to set the relay
    unsigned long previousMillis; // will store last time relay was updated

    // Constructor - creates a Flasher
    // and initializes the member variables and state
public:
    DelayTimer(int pin, long delayTm)
    {
        relayPin = pin;
        delayTime = delayTm;
        pinMode(relayPin, OUTPUT);

        relayState = LOW;
        triggered = false;
        previousMillis = 0;
    }

    void Update(int number)
    {
        // check to see if it's time to change the state of the relay
        unsigned long currentMillis = millis();

        if ((relayState == LOW) && (currentMillis - previousMillis >= delayTime) && (triggered == false))
        {
            relayState = HIGH;
            triggered = true;               // turn it on
            previousMillis = currentMillis; // Remember the time
            digitalWrite(relayPin, relayState);
            Serial.print("Relay ");
            Serial.print(number);
            Serial.print(" : ");
            Serial.println("HIGH");
        }
    }
};