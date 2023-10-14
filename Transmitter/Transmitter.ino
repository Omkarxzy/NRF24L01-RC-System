
#include<nRF24L01.h>
#include<RF24.h>
#include<SPI.h>

//Pins of the 2 Joysticks
#define x1Pin A0
#define y1Pin A1
#define x2Pin A2
#define y2Pin A3

//Potentiomter Pin
#define potPin A4

//2 Toggle Switch Pins
#define toggle1 2
#define toggle2 3

//4 PushButtons Pins
#define button1 4
#define button2 5
#define button3 6
#define button4 9

RF24 radio(7,8); //declaring CE and CSN pins
//RF24 is a class, creating a OBJECT radio
const byte address[]="node0"; //address can be anyting,but it should contain 5 letters

void setup() {
  // put your setup code here, to run once:
radio.begin(); //intializes the operations of Chip
radio.openWritingPipe(address);
radio.setPALevel(RF24_PA_LOW); 
/* the above function is used to set the value of PowerAmplifier Range
   you can either set PALevel to MIN , LOW , HIGH , MAX
*/
radio.setDataRate(RF24_250KBPS); //There are 3 DataRates: 250KBPS , 1MBPS , 2MBPS
radio.stopListening(); //this function stops the nRF24L01 module from reading any data

Serial.begin(9600);
pinMode(x1Pin,INPUT);
pinMode(y1Pin,INPUT);
pinMode(x2Pin,INPUT);
pinMode(y2Pin,INPUT);
pinMode(potPin,INPUT);
pinMode(toggle1,INPUT_PULLUP);
pinMode(toggle2,INPUT_PULLUP);
pinMode(button1,INPUT_PULLUP);
pinMode(button2,INPUT_PULLUP);
pinMode(button3,INPUT_PULLUP);
pinMode(button4,INPUT_PULLUP);

}
struct datapack{
   float x1Val;
   float y1Val;
   float x2Val;
   float y2Val;
   float potVal;
   bool toggle1Val; // bool is a DataType , which it  either stores 0 or 1
   bool toggle2Val;
   bool button1Val;
   bool button2Val;
   bool button3Val;
   bool button4Val;       
};

datapack data; //here we created a variable named data whose datatype is datapack

void loop() {
  // put your main code here, to run repeatedly:
data.x1Val=map(analogRead(x1Pin) , 0,1023 , 0,255);
data.y1Val=map(analogRead(y1Pin) , 0,1023 , 0,255);
data.x2Val=map(analogRead(x2Pin) , 0,1023 , 0,255);
data.y2Val=map(analogRead(y2Pin) , 0,1023 , 0,255);
data.potVal=map(analogRead(potPin) , 0,1023 , 0,255);
data.toggle1Val=digitalRead(toggle1);
data.toggle2Val=digitalRead(toggle2);
data.button1Val=digitalRead(button1);
data.button2Val=digitalRead(button2);
data.button3Val=digitalRead(button3);
data.button4Val=digitalRead(button4);

radio.write(&data , sizeof(data));
/* write function is used to send the data , 
    we need to call stopListening function before calling write Function 
   "&"=Ampersand Symbol , & represents the 'Address of the Operator/Variable'
    "sizeof" is function of C++ , used to obtain the size of the Operator/Variable
*/

Serial.println(data.x1Val);
Serial.println(data.y1Val);
Serial.println(data.x2Val);
Serial.println(data.y2Val);
Serial.println(data.potVal);
Serial.println(data.toggle1Val);
Serial.println(data.toggle2Val);
Serial.println(data.button1Val);
Serial.println(data.button2Val);
Serial.println(data.button3Val);
Serial.println(data.button4Val);
Serial.println();


}
