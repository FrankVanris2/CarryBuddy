#include "Arduino.h"
#include "CBState.h"
#include "CarryBuddyMgr.h"

/*
* By: Frank C Vanris
* Date: 9/12/2022
* Description: Contains the whole setup for my CarryBuddy. This is where all of the movements and
* mechanics will go. Contains a Setup and Loop like CarryBuddy.ino.
*/

//state machine starter
CarryBuddyMgr::CarryBuddyMgr(): mState(CALC_POSITION) {}

//your setup code: somewhat like main
void CarryBuddyMgr::setup() { mMotor.setup(); }

//loops through the program
void CarryBuddyMgr::loop() { handleState(); }

//CarryBuddy State Machine
void CarryBuddyMgr::handleState() {
    switch (mState) {
    //activation period.

    case CALC_POSITION:
        mGrid.calNxtPos();
        mState = StateEnum::TURN;
        break;
    
    //moving period
    case StateEnum::MOVE:
        mMotor.move(mGrid.getDistance());

        //stop after 1 minute
        if (millis() > 60000) {
            mState = StateEnum::STOP;
        }
        else {

            //else Calc next position
            mState = StateEnum::CALC_POSITION;
        }   
        break;
    
    //turning period
    case StateEnum::TURN:
        mMotor.turn(mGrid.getAngle());
        mState = StateEnum::MOVE;
        break;

    //stops both motors
    case StateEnum::STOP:
        mMotor.stop();
        mState = StateEnum::STOP;
        break;  
    }
}

