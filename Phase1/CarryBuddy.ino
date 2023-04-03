/*
 Name:		CarryBuddy.ino
 Created:	2/5/2023 4:26:41 PM
 Author:	Frank C Vanris
 Summary: This is Prototype 1 of my CarryBuddy Project, this project is based on movement
 within a Grid.
*/
#include <Arduino.h>
#include "./CarryBuddyMgr.h"

//we are going to instantiate a class that I created
CarryBuddyMgr carryBuddyMgr;

// the setup function runs once when you press reset or power the board
void setup() { 
    carryBuddyMgr.setup(); 
}

// the loop function runs over and over again until power down or reset
void loop() { 
    carryBuddyMgr.loop(); 
}
 