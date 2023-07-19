#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>                 //https://github.com/tmrh20/RF24/
#include <Wire.h>
#include "BUZZER.h"
#include "JOYSTICK.h"
#include "PUSHBUTTON.h"
#include "TOGGLESWITCH.h"
//#include <MPU6050.h>

//Toggle switch pins declaration and object
#define tglPin1 6                 // Toggle switch 1
#define tglPin2 7                 // Toggle switch 1
toggleSwitch tgl1(tglPin1);
toggleSwitch tgl2(tglPin2);

//Potentiometer pins declaration and object
// #define potPin1 A6                // Toggle switch 1
// #define potPin2 A7                // Toggle switch 1
// potentiometer pot1(potPin1);
// potentiometer pot2(potPin2);

//Joystick pin declaration and object declaration
#define joyXaxisPin1 A0           // Joystick X axis 1
#define joyYaxisPin1 A1           // Joystick Y axis 1
#define joyBtn1 0
#define joyXaxisPin2 A2           // Joystick X axis 1
#define joyYaxisPin2 A3           // Joystick Y axis 1
#define joyBtn2 1                 // Toggle switch 1
joystick joystick1(joyXaxisPin1,joyYaxisPin1,joyBtn1);
joystick joystick2(joyXaxisPin2,joyYaxisPin2,joyBtn2);

//Pushbuttons pin declaration and object declaration
#define btnPin1 8                 // Button 1
#define btnPin2 9                 // Button 2
#define btnPin3 2                 // Button 3
#define btnPin4 3                 // Button 4
pushButton btn1(btnPin1);
pushButton btn2(btnPin2);
pushButton btn3(btnPin3);
pushButton btn4(btnPin4);

//Buzzer pin
#define buzzPin 10                //buzzPiner
buzzer buzz(buzzPin);

//nRf24L01 module pins
#define CE 5
#define CSN 6
RF24 radio(CE,CSN);              // nRF24L01 (CE, CSN)
const byte address[6] = "00001"; // Address

//MPU6050
// MPU6050 mpu;

// Max size of this struct is 32 bytes - NRF24L01 buffer limit
struct Data_Package 
{
  byte joy1Xaxis;
  byte joy1Yaxis;
  byte j1Button;
  byte joy2Xaxis;
  byte joy2Yaxis;
  byte j2Button;
  // byte pot1val;
  // byte pot2val;
  byte tSwitch1Val;
  byte tSwitch2Val;
  byte button1Val;
  byte button2Val;
  byte button3Val;
  byte button4Val;
  // byte pitchVal;
  // byte rollVal;
};
Data_Package data; //Create a variable with the above structure