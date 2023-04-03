#pragma once
/*
* By: Frank C Vanris
* Date: 9/18/2022
* Description: Contains all of my States for my state machine.
*/

//X and Y for the array
static const int X = 0;
static const int Y = 1;

//States
enum StateEnum {  

    //The States
    CALC_POSITION,
    MOVE,
    TURN,
    STOP
};


