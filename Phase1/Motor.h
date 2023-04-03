#pragma once
#include "CBState.h"
/*
* By: Frank C Vanris
* Date: 9/18/2022
* Description: contains the functions for the robot to move, turn stop, speed up, and slow down
* also includes countless constants that can only be changed here as well.
*/

class Motor {
public:
    void setup();

    //States
    StateEnum move(float distance);
    StateEnum turn(float angle);
    StateEnum stop();

private: 

    //Vehicle and Wheel measurements
    static const float VEHICLE_RADIUS;
    static const float WHEEL_RADIUS;

    //Time for movements of device
    static const int WHEEL_ROTATION_TIME_MOVE = 375; //ms
    static const int WHEEL_ROTATE_TIME_TURN = 1000; //ms
    static const int STARTUP_TIME = 0; // ms

    //Speed of motor
    static const int MAX_SPEED = 255;
    static const int MOTOR_SPEED = 235;

    //Motor Pin connections
    static const int M1_SPEED_PIN = 5;
    static const int M1_DIRECTION_1 = 4;
    static const int M1_DIRECTION_2 = 3;

    static const int M2_SPEED_PIN = 9;
    static const int M2_DIRECTION_1 = 10;
    static const int M2_DIRECTION_2 = 11;

    //LED controls
    static const int LED_BUILTINPIN = 13;

    //starting Speeds of motors
    int mM1Speed = 0;
    int mM2Speed = 0;

    //angleRotation/distance Rotation time
    static float angleToRotationTime(float angle);
    static float distanceToRotationTime(float distance);
};

