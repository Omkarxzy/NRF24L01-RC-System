#ifndef buzzer_h
#define buzzer_h

#if (ARDUINO >= 100) 
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

class buzzer
{
private:
  uint8_t buzzPin;
  
public:
  //Function prototype
  inline buzzer(uint8_t) __attribute__((always_inline));
  inline void begin() __attribute__((always_inline));
  inline void on() __attribute__((always_inline));
  inline void off() __attribute__((always_inline));
  inline ~buzzer() __attribute__((always_inline));
};


//Parametrized constructor
buzzer::buzzer(uint8_t buzzPin)
{
  this->buzzPin = buzzPin;

  begin();
}

void buzzer::begin()
{
  pinMode(buzzPin, OUTPUT);
  off();
}

void buzzer::off()
{
  digitalWrite(buzzPin, LOW);
}

void buzzer::on()
{
  digitalWrite(buzzPin, HIGH);
}

//Destructor
buzzer::~buzzer()
{
  Serial.println("buzzer object destroyed"); 
}

#endif  //END BUZZER_H
