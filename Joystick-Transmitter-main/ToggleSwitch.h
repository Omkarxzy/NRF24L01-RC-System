#ifndef TOGGLESWITCH_h
#define  TOGGLESWITCH_h

#if (ARDUINO >= 100) 
  #include "Arduino.h"
//#else
  //#include "WProgram.h"
#endif

class toggleSwitch
{
	private:
		uint8_t togglePin;
	public:
		//Function prototype
		inline toggleSwitch(uint8_t) __attribute__((always_inline));
		inline void begin() __attribute__((always_inline));
		inline bool read() __attribute__((always_inline));
		inline ~toggleSwitch() __attribute__((always_inline));
};

//Parametrized constructor
toggleSwitch::toggleSwitch(uint8_t togglePin)
{
  this->togglePin = togglePin;

  begin();
}

void toggleSwitch::begin()
{
  pinMode(togglePin, INPUT);
}

bool toggleSwitch::read()
{
	return (bool)digitalRead(togglePin);
}

toggleSwitch::~toggleSwitch()
{
	Serial.println("ToggleSwitch is destroyed");
}

#endif //TOGGLESWITCH
		
