/*
 * written by Jacob Bader
 * 2/24/2018
 *
 * For Pololu mc33926 DC motor driver
 */

#include "mc33926.h"
#include "Arduino.h"

/**
 * creates a motor controller object
 * @param PWMPin must be PWM pin, used for speed control
 * @param dirPin pin to control direction
 */
mc33926::mc33926(int PWMPin, int dirPin) {
    _pinDir = dirPin;
    _pinPWM = PWMPin;
    pinMode(_pinPWM, OUTPUT);
    analogWrite(_pinPWM, 0);
    pinMode(_pinDir, OUTPUT);
    digitalWrite(_pinDir, LOW);
}

/**
 * sets the motor speed
 * @param velocity -100 to 100
 * -100 is full backwards
 * 100 is full forwards
 * 0 is stop
 */
void mc33926::setMotorVelocity(int velocity) {
    if(velocity > 100){
        velocity = 100;
    }else if(velocity < -100){
        velocity = -100;
    }

    if(velocity > 0){
        digitalWrite(_pinDir, HIGH);
        analogWrite(_pinPWM, (int)(velocity*2.55));
    }else if(velocity < 0){
        digitalWrite(_pinDir, LOW);
        analogWrite(_pinPWM, (int)(velocity*2.55));
    }else {
        analogWrite(_pinPWM, 0);
    }

}

/**
 * stops the motor s
 */
void mc33926::stopMotor() {
    analogWrite(_pinPWM, 0);
}
