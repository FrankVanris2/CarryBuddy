#include <Arduino.h>
#include "CBState.h"
#include "Motor.h"

/*
* By: Frank C Vanris
* Date: 9/18/2022
* Description: contains the code for every function that was made in Motor.h and includes
* everything from the Arduino.h library. Also all of this programming is made in C++ version 8
* so it's old (REMEMBER THAT)
*/

using namespace std;

//Initializing the vehicle measurements
const float Motor::VEHICLE_RADIUS =  17.3 / 2; //cm
const float Motor::WHEEL_RADIUS = 6.6 / 2; //cm

//my setup code
void Motor::setup() {
    //LED
    pinMode(LED_BUILTINPIN, OUTPUT);

    //Motors
    pinMode(M1_SPEED_PIN, OUTPUT);
    pinMode(M1_DIRECTION_1, OUTPUT);
    pinMode(M1_DIRECTION_2, OUTPUT);

    pinMode(M2_SPEED_PIN, OUTPUT);
    pinMode(M2_DIRECTION_1, OUTPUT);
    pinMode(M2_DIRECTION_2, OUTPUT);
}

//count the number of steps.
StateEnum Motor::move(float distance) {

    //LED on when moving
    digitalWrite(LED_BUILTINPIN, HIGH);

    //calculating the distance time
    float distanceTime = distanceToRotationTime(distance);
    
    //movement in one direction
    digitalWrite(M1_DIRECTION_1, HIGH);
    digitalWrite(M1_DIRECTION_2, LOW);

    digitalWrite(M2_DIRECTION_1, HIGH);
    digitalWrite(M2_DIRECTION_2, LOW);

    //starting speed from 0 is now to regular motor speed which is 235
    mM1Speed = MOTOR_SPEED;
    mM2Speed = MOTOR_SPEED;

    //speed change 
    analogWrite(M1_SPEED_PIN, mM1Speed);
    analogWrite(M2_SPEED_PIN, mM2Speed);
    
    //delay after the motors are turned on
    delay(distanceTime);
}

//turning in an angle with time applied
float Motor::angleToRotationTime(float angle) {
    
    //returing angle of rotation time
    float wheelDistance = (2 * PI * VEHICLE_RADIUS) * (fabs(angle) / 360);

    //getting the number of rotations it would take for it to go to that destination
    float rotationsPerWheel = wheelDistance / (2 * PI * WHEEL_RADIUS);

    //the time it take for the number of rotations within that turn
    float rotationTime = rotationsPerWheel * WHEEL_ROTATE_TIME_TURN + STARTUP_TIME;

    return rotationTime;
}

//getting the distance to rotation time for when the object is moving
float Motor::distanceToRotationTime(float distance) {

    //returning the distance of rotation time.
    return WHEEL_ROTATION_TIME_MOVE / (2 * PI * WHEEL_RADIUS) * distance;
}

//Turning State
StateEnum Motor::turn(float angle) {
    //LED is off when robot is turning
    digitalWrite(LED_BUILTINPIN, LOW);

    //determining turn of robot
    if (angle >= 0) {
        digitalWrite(M1_DIRECTION_1, LOW);
        digitalWrite(M1_DIRECTION_2, HIGH);

        digitalWrite(M2_DIRECTION_1, HIGH);
        digitalWrite(M2_DIRECTION_2, LOW);
    }
    else {
        digitalWrite(M1_DIRECTION_1, HIGH);
        digitalWrite(M1_DIRECTION_2, LOW);

        digitalWrite(M2_DIRECTION_1, LOW);
        digitalWrite(M2_DIRECTION_2, HIGH);
    }

    //num of moving steps via the angle of rotation
    float rotationTime = angleToRotationTime(angle);
    
    //speed of motor changes again from 0 to 235
    mM1Speed = MOTOR_SPEED;
    mM2Speed = MOTOR_SPEED;

    //pin speed change
    analogWrite(M1_SPEED_PIN, mM1Speed);
    analogWrite(M2_SPEED_PIN, mM2Speed);

    //delay after the motors are turned on
    delay(rotationTime);
}

//stopping the device after a minute
StateEnum Motor::stop() {

    mM1Speed = 0;
    mM2Speed = 0;
    analogWrite(M1_SPEED_PIN, mM1Speed);
    analogWrite(M2_SPEED_PIN, mM2Speed);

    //LED blinks when it switches off.
    while (true) {
        digitalWrite(LED_BUILTINPIN, HIGH);
        delay(1000);
        digitalWrite(LED_BUILTINPIN, LOW);
        delay(1000);
    }
}


