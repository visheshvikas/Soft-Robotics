#ifndef MotorActuator_h
#define MotorActuator_h
#include "Arduino.h"

class MotorActuator
{
  public:
    MotorActuator();  
    void setPin(int pinA, int pinB);
    void turnOff();
    void turnOn_CW();
    void turnOn_CCW();
    void setParameters(int phi, int activeT);  
    int getPhi();
    void setPhi(int);
    int getActiveT();
    void setActiveT(int);
    int getSliderVal();
    void setSliderVal(int);
    void implementState(int);
    void setState(int);
    int getCurrentState();
    
  private:
    int _pinA;
    int _pinB;
    int _phi;
    int _activeT;
    int _sliderVal;
    int _currentState;
};
#endif
