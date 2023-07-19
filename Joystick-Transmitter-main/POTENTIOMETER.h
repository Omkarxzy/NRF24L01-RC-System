#ifndef POTENTIOMETER_H
#define POTENTIOMETER_H

#if (ARDUINO >= 100)
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

class potentiometer
{
private:
    uint8_t potPin;

public:
    // Function prototype
    inline potentiometer(uint8_t) __attribute__((always_inline));
    inline void begin() __attribute__((always_inline));
    inline bool read() __attribute__((always_inline));
    inline ~potentiometer() __attribute__((always_inline));
};

// Parametrized constructor
potentiometer::potentiometer(uint8_t potpin)
{
    this->potPin = potPin;

    begin();
}

void potentiometer::begin()
{
    pinMode(potPin, INPUT);
}

bool potentiometer::read()
{
    return (bool)analogRead(potPin);
}

// Destructor
potentiometer::~potentiometer()
{
    Serial.println("potentiometer object destroyed");
}

#endif // END BUZZER_H
