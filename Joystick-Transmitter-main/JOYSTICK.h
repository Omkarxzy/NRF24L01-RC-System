#ifndef JOYSTICK_h
#define JOYSTICK_h

#if (ARDUINO >= 100)
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

class joystick
{
private:
  uint16_t xAxis, yAxis;
  bool pushP;
    
public:
  inline joystick(uint16_t, uint16_t, bool) __attribute__((always_inline));
  inline void begin() __attribute__((always_inline));
  inline uint16_t readX() __attribute__((always_inline));
  inline uint16_t readY() __attribute__((always_inline));
  inline bool readPushPin() __attribute__((always_inline));
  inline ~joystick() __attribute__((always_inline));
};

joystick::joystick(uint16_t xAxis, uint16_t yAxis, bool pushP)
{
  this->xAxis = xAxis;
  this->yAxis = yAxis;
  this->pushP = pushP;
  begin();
}
void joystick::begin()
{
  pinMode(xAxis, INPUT);
  pinMode(yAxis, INPUT);
  pinMode(pushP, INPUT_PULLUP);
}

uint16_t joystick::readX()
{
  return (int)analogRead(xAxis)/4;    //0 - 1023
}

uint16_t joystick::readY()
{
  return (int)analogRead(yAxis)/4;
}

bool joystick::readPushPin()
{
  if(digitalRead(pushP))
    return true;
  else
    return false;
}

joystick::~joystick()
{
    Serial.println("input ded");
}

#endif
