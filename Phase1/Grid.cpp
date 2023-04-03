#include <Arduino.h>
#include "Grid.h"
#include "CBState.h"
#include <math.h>

/*
* By: Frank C Vanris
* Date: 9/13/2022
* Description: created a 200cm by 200cm Grid. For the CarryBuddy to follow
* and created the different changes in directions the robot must follow.
* It can only follow my calculations.
*/

//The Grid is getting the CurrentPos
Grid::Grid()  { mCurrentPos; }

//getting next position
void Grid::calNxtPos() {
    int temp[2];
    int dif[2];

    //checking if there are any repetitions for when the distance does not change.
    //if it didn't re-roll again.
    do {
        //get the x and y
        temp[X] = rand() % GRID_SIZE;
        temp[Y] = rand() % GRID_SIZE;

        dif[X] = temp[X] - mCurrentPos[X];
        dif[Y] = temp[Y] - mCurrentPos[Y];

    } while (dif[X] == 0 && dif[Y] == 0);

    //current pos for x and y is equal to the temp x and y
    mCurrentPos[X] = temp[X];
    mCurrentPos[Y] = temp[Y];

    //pythagorus: distance: c = sqrt(a^2 + b^2)
    mDistance = sqrt(dif[X] * dif[X] + dif[Y] * dif[Y]);

   //setting up tan and last angles
    float tanAngle;
    float lastAngle;

    //if angle of X > 0
    if (dif[X] > 0) {
        tanAngle = dif[Y] / (float) dif[X];
        lastAngle = atan(tanAngle) * (180 / M_PI);
        mDiffAngle = mLastAngle - lastAngle;

        //if angle of X < 0 angle goes to quadrant 4
    } else if (dif[X] < 0) {
        tanAngle = dif[Y] / (float) (-dif[X]);
        if (dif[Y] >= 0)
            lastAngle = (M_PI - atan(tanAngle)) * (180 / M_PI);
        else
            lastAngle = (-M_PI - atan(tanAngle)) * (180 / M_PI);
    }
    else {

        //if Y is positive or negative become 90 degrees or -90 degrees.
        if (dif[Y] > 0) {
            lastAngle = 90;
        }
        else {
            lastAngle = -90;
        }
    }

    //diffAngle = B - A, new angle we are creating due to the previous angle.
    mDiffAngle = lastAngle - mLastAngle;
    mLastAngle = lastAngle;
}