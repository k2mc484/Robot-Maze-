#ifndef HOMEWORK3_ROBOTMOVEMENT_H
#define HOMEWORK3_ROBOTMOVEMENT_H
#include "robot.h"


/*-----------------------------------------------------------------------------
 * Function name: sendRobotToTerminal
 * Description: This function makes the robot move through the track to
 *              reach terminal stopNum.
 *              The function returns 1 if the terminal was found, 0 otherwise
 *
 * PSEUDOCODE HERE
 * 1.Loop sends the robot until it hits the desired hallway
 *      a.Calls followSegment function
 * 2. If statement testing less than 5 stops.
 *      A.If statement
 *          a.robot turns right
 *          b.Returns true to turnRight function
 *      B.Else If statement
 *          a.robot turns left
 *          b.Returns true to turnLeft function
 *      C.Robot continues down side hallway
 *      D.Returns 1
 * 3.Call function setNoLastTurn
 * 4.Returns 0
  ----------------------------------------------------------------------------*/
extern int sendRobotToTerminal(Robot *robot, const int stopNum);


/*-----------------------------------------------------------------------------
 * Function name: returnToStart
 * Description: This function makes the robot return to the main station.
 *              The function returns 1 if found, 0 otherwise

 *
 * PSEUDOCODE HERE
 * 1.Robot does a uTurn
 * 2.Robot goes back down the side hallway.
 * 3.If statement checking if the lastTurn was right
 *      A. Robot turns left
 * 4.Else if statement checking if the lastTurn was left
 *      A.Robot turns right
 * 5.While statement checking if the robot is not at the end
 *      A.Robot continues straight
 * 6.Robot does uTurn to be ready for the next game
 * 7.Return 1
  ----------------------------------------------------------------------------*/
extern int returnToStart(Robot *robot);

#endif // HOMEWORK3_ROBOTMOVEMENT_H
