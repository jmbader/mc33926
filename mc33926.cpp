/*
 * written by Jacob Bader
 * updated 3/12/2018
 */

#include "mc33926.h"
#include "Arduino.h"

/**
 *
 * default constructor
 * do not use this
 */
mc33926::mc33926() {
    //Do nothing
}

/**
 *
 * @param PWMPin the pwm pin the motor controller is connected to
 * @param dirPin any dio on the arduino, it controls direction
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

    if (velocity > 100) {
        //if velocity is greater than 100 set it to 100
        velocity = 100;
    } else if (velocity < -100) {
        //if velocity is less than -100 set it to -100
        velocity = -100;
    }

    // 100 vel = 0 analog
    //

    analogWrite(_pinPWM, (int)((abs(velocity)) * (-255/100) + 255));

    if (velocity > 0) {
        //positive velocity
        digitalWrite(_pinDir, HIGH);
    } else if (velocity < 0) {
        //negative velocity
        digitalWrite(_pinDir, LOW);
    } else {
        //stop the motor
        analogWrite(_pinPWM, 0);
    }

}

/**
 * stops the motor
 */
void mc33926::stopMotor() {
    //stops the motor
    analogWrite(_pinPWM, 255);
}
