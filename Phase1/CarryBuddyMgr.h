#pragma once
#include "CBState.h"
#include "Grid.h"
#include "Motor.h"

/*
* By: Frank C Vanris
* Date: 9/12/2022
* Description: CarryBuddyManager.h creates the main functions. Such as Setup and Loop.
* It also creates seperate objects for the Motor and Grid class. including a new one known
* as State which will help us create a state machine.
*/


using namespace std;


class CarryBuddyMgr {
public: 
    
    //constructor
    CarryBuddyMgr();

    void setup();
    void loop();

private: 

    //handling states method
    void  handleState();

    //State, Grid, and Motor objects
    StateEnum mState;
    Grid mGrid;
    Motor mMotor;
};
