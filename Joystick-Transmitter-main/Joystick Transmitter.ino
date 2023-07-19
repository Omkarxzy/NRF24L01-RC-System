#include "GLOBALS.h"

void setup() {
  Serial.begin(9600);

  // Serial.println("Initialize MPU6050");
  // while(!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G))
  // {
  //   Serial.println("Could not find a valid MPU6050 sensor, check wiring!");
  //   delay(500);
  // }
  
  
  // radio communication
  radio.begin();
  radio.openWritingPipe(address);
  radio.setAutoAck(false);
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_LOW);
  
  // initial default values
  data.joy1Xaxis = 127;
  data.joy1Yaxis = 127;
  data.j1Button = 1;
  data.joy2Xaxis = 127;
  data.joy1Yaxis = 127;
  data.j2Button = 1;
  // data.pot1val = 1;
  // data.pot2val = 1;
  data.tSwitch1Val = 1;
  data.tSwitch2Val = 1;
  data.button1Val = 1;
  data.button2Val = 1;
  data.button3Val = 1;
  data.button4Val = 1;
  // data.pitchVal = 0;
  // data.rollVal = 0;
  
}


void loop() {
  
  // Read normalized values 
  //Vector normAccel = mpu.readNormalizeAccel();

  // Calculate pitchVal & rollVal
  // int pitchVal = -(atan2(normAccel.XAxis, sqrt(normAccel.YAxis*normAccel.YAxis + normAccel.ZAxis*normAccel.ZAxis))*180.0)/M_PI;
  // int rollVal = (atan2(normAccel.YAxis, normAccel.ZAxis)*180.0)/M_PI;
  
  // Read all analog inputs and map them to one Byte value
  data.joy1Xaxis = joystick1.readX(); // Convert the analog read value from 0 to 1023 into a BYTE value from 0 to 255
  data.joy1Yaxis = joystick1.readY();
  data.joy2Xaxis = joystick2.readX();
  data.joy2Yaxis = joystick2.readY();
  // data.pot1Val = pot1.read();
  // data.pot2Val = pot2.read();
  // Read all digital inputs
  data.j1Button = joystick1.readPushPin();
  data.j2Button = joystick2.readPushPin();
  data.tSwitch2Val = tgl1.read();
  data.tSwitch1Val = tgl2.read();
  data.button1Val = btn1.read();
  data.button2Val = btn2.read();
  data.button3Val = btn3.read();
  data.button4Val = btn4.read();
  // data.pitchVal = (pitchVal);
  // data.rollVal = (rollVal);
  
  radio.write(&data, sizeof(Data_Package)); // Send the whole data from the structure to the receiver
  
}
