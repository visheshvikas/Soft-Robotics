#include "Arduino.h"
#include "MotorActuator.h"
MotorActuator::MotorActuator(){
}

// sets the Pins for actuation
void MotorActuator::setPin(int pinA, int pinB){
  _pinA = pinA;
  _pinB = pinB;
  pinMode(_pinA, OUTPUT);
  pinMode(_pinB, OUTPUT);
  // Initially both are set to low
  turnOff();
}

void MotorActuator::turnOff(){
  digitalWrite(_pinA, LOW);
  digitalWrite(_pinB, LOW);
}

void MotorActuator::turnOn_CW(){	
  digitalWrite(_pinA, HIGH);
  digitalWrite(_pinB, LOW);
}

void MotorActuator::turnOn_CCW(){  
  digitalWrite(_pinA, LOW);
  digitalWrite(_pinB, HIGH);
}

void MotorActuator::setParameters(int phi, int activeT){
	setPhi(phi);
        setActiveT(activeT);
}
void MotorActuator::setPhi(int phi){
	_phi = phi/10;
      _phi = _phi*10;
}

void MotorActuator::setActiveT(int activeT){
	_activeT = activeT;
}

int MotorActuator::getPhi(){
	return _phi;
}
int MotorActuator::getActiveT(){
	return _activeT;
}

int MotorActuator::getSliderVal(){
  return _sliderVal;
}

void MotorActuator::setSliderVal(int sliderVal){
  _sliderVal = sliderVal;
}

void MotorActuator::setState(int theState)
{
  _currentState=theState;
}

int MotorActuator::getCurrentState()
{
  return _currentState;
}

void MotorActuator::implementState(int theState){
  if(theState==0)       //stopped
  {
    turnOff();
  }
  else if(theState==1)   //CW
  {
    turnOn_CW();
  }
  else if(theState==2)   //CCW
  {
    turnOn_CCW();
  }
  setState(theState);
}

