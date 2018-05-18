#include "robotMovement.h"
#include "pololu/3pi.h"
#include "robot.h"
#include "robot_utils.h"

/*TODO: Implement this function*/
int sendRobotToTerminal(Robot *robot, const int stopNum) {
    //Loop sends the robot until it hits the desired hallway
    for (int i = 0; i < stopNum; i++) {
        robot->followSegment();
        if (!robot->lineAhead()) {
            //If the desired hallway is greater than how many hallways exist then the setNoLastTurn function is called.
            //This saves the lastTurn to the char 'N' so that the returnToStart function works when the robot passes all hallways.
            robot->setNoLastTurn();
            return 0;
        }
    }
    //Turns the robot into the desired hallway and saves the last turn to right
    if (robot->lineToRight()) {
        robot->turnRight(true);
    }//Turns the robot into the desired hallway and saves the last turn to left
    else if (robot->lineToLeft()) {

        robot->turnLeft(true);
    }
    robot->followSegment();
    return 1;
}

/*TODO: Implement this function*/
int returnToStart(Robot *robot) {
    //Robot does a uTurn
    robot->uTurn();
    //Robot goes back to main hallway
    robot->followSegment();
    //Tests what direction it came from so it turns the correct way back to home
    if (robot->getLastTurn() == 'R') {
        //Turns the opposite way from its previous turn
        robot->turnLeft();
    }//Tests what direction it came from so it turns the correct way back to home
    else if (robot->getLastTurn() == 'L') {
        //Turns the opposite way from its previous turn
        robot->turnRight();
    }
    //The robot continues straight until it hits the home base again. This is done by testing that the robot is
    //not at the home base
    while (!robot->atEnd()) {
        robot->followSegment();
    }
    //The robot turns around so that it is ready for the next round.
    robot->uTurn();
    return 1;
}
