#ifndef MC33926_LIBRARY_H
#define MC33926_LIBRARY_H

#include "Arduino.h"

class mc33926{
public:
    mc33926(int, int);
    void setMotorVelocity(int);
    void stopMotor();
private:
    int _pinPWM;
    int _pinDir;
};

#endif