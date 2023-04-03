#pragma once
//#include <vector>
/*
* By: Frank C Vanris
* Date: 9/13/2022
* Description: Contains the methods that will construct the grid and return
* the next point and turn for the robot.
*/

class Grid {
public:

    //Grid
    Grid();

    //getting next position
    void calNxtPos();

    //returning the new angle
    float getAngle() const {
        return mDiffAngle;
    };

    //returning the new distnce
    float getDistance() const {
        return mDistance;
    }
   
private:
    
    //Grid size for both the x and y
    static const int GRID_SIZE = 200; //cm

    //The grid is setted up in an array
    int mCurrentPos[2] = {0, 0};

    float mDiffAngle = 0;  //angle difference for when it changes
    float mLastAngle = 90;  //starting off at 90 degrees
    float mDistance = 0; //distance for how far the robot must go    
};

