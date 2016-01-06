
#include "MotorActuator.h"

int key;
// Motors and parameters
const int noofLimbs = 4;
MotorActuator limbMotors[noofLimbs];
int pinA[] = {10, 8, 6, 4, 2};
int pinB[] = {11, 9, 7, 5, 3};

void setup() {
  //Serial communication rate
  Serial.begin(115200);

  //    3. Initializing Motors and their parameters - all in milliseconds (ms)
  //    3a. Set pins
  for(int ii=0; ii<noofLimbs; ii++)
  {
    limbMotors[ii].setPin(pinA[ii],pinB[ii]);
    limbMotors[ii].setState(0);    
  }
}

void loop()
{
  if (Serial.available() > 0) 
  {
    while (Serial.peek() == 'L') 
    { //check for the character that signifies that this will be a command
      Serial.read(); //remove the L off the serial buffer
      for (int ii = 0; ii < noofLimbs; ii++)
      {
        Serial.read(); //removes the S
        limbMotors[ii].implementState(Serial.parseInt());
      }
    }
    clearBuffer();
  }
}

void clearBuffer()
{
  while (Serial.available() > 0) { //Discard everything that we didn't expect
    Serial.read();
  }
}

