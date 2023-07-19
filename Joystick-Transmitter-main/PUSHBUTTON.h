#ifndef PUSH_BUTTON_h
#define PUSH_BUTTON_h

#if (ARDUINO >= 100) 
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

class pushButton
{
private:
  uint8_t pushPin;
  
public:
  //Function prototype
  inline pushButton(uint8_t) __attribute__((always_inline));
  inline void begin() __attribute__((always_inline));
  inline bool read() __attribute__((always_inline));
  inline ~pushButton() __attribute__((always_inline));
};


//Parametrized constructor
pushButton::pushButton(uint8_t pushpin)
{
  this->pushPin = pushPin;

  begin();
}

void pushButton::begin()
{
  pinMode(pushPin, INPUT_PULLUP);
}

bool pushButton::read()
{
  return (bool)digitalRead(pushPin);

}

//Destructor
pushButton::~pushButton()
{
  Serial.println("pushButton object destroyed"); 
}

#endif  //END BUZZER_H
