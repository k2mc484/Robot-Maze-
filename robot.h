/*-------------------------------------------------------------------------------
* Name: robot.h
* Description: This file contains a structure and associated function
*              prototypes to model a robot. A Robot object
*              has members to model its current position.
*              Functions are provided to modify the current position and
*              direction of a given robot to follow a segment,
*              move left, move right, and make a u-turn.
*              Also the robot has access to read its sensors to
*              survey the surroundings.
-------------------------------------------------------------------------------*/
#ifndef ROBOT_H
#define ROBOT_H

#include "pololu/3pi.h"
#include "robot_utils.h"
#include "sensors.h"

class Robot {
public:

/*-----------------------------------------------------------------------------
 * Function name: bat_check
 * Description: This function checks the voltage on the batteries and
 *              displays a message on the LCD until the user presses B.
 *              The message on the first line cycles between the following:
 *              Bat Chk       [-> descriptive message]
 *              xxxxmV        [-> the battery voltage]
 *              Okay/Replace  [-> whether the batteries should be replaced]
 ----------------------------------------------------------------------------*/
    void bat_check(void);

/*-----------------------------------------------------------------------------
 * Function name: stopRobot
 * Description: This function (based on a very similar function written by
 *              pololu) stops the robot.
  ----------------------------------------------------------------------------*/
    void stopRobot();

/*-----------------------------------------------------------------------------
 * Function name: turnLeft
 * Description: This function modifies the given robot's position and direction
 *              so that the robot turns and moves one unit to the left.
 * 	            When turnLeft is called with argument true, 'L' is recorded
 *				in the lastTurn data member
 ----------------------------------------------------------------------------*/
    void turnLeft();

    void turnLeft(bool remember);

/*-----------------------------------------------------------------------------
 * Function name: turnRight
 * Description: This function modifies the given robot's position and direction
 *              so that the robot turns and moves one unit to the right.
 * 	            When turnRight is called with argument true, 'R' is recorded
 *				in the lastTurn data member
  ----------------------------------------------------------------------------*/
    void turnRight();

    void turnRight(bool remember);

/*-----------------------------------------------------------------------------
 * Function name: uTurn
 * Description: This function modifies the given robot's position and direction
 *              so that the robot performs a 180 degree turn and moves
 *              one unit in the new direction.
 ----------------------------------------------------------------------------*/
    void uTurn();

/*-----------------------------------------------------------------------------
 * Function name: get_surrounding_status
 * Description: Returns a reference to a Sensors object to determine wheather
 *              there is black to the left, front, right, or the robot is at the
 *              end of the track (main station)
 */
    const Sensors &get_surrounding_status();

/*-----------------------------------------------------------------------------
 * Function name: getLastTurn
 * Description: Returns the lastTurn data member.
 * Output: char = the last turn recorded
 ----------------------------------------------------------------------------*/
    char getLastTurn() const;

    /*-----------------------------------------------------------------------------
 * Function name: setNoLastTurn
 * Description: sets lastTurn to 'N'.
 * Output: char = 'N'
 ----------------------------------------------------------------------------*/
    void setNoLastTurn();

    /*-----------------------------------------------------------------------------
     * Funciton name: followSegment
     * Description: The robot goes straight until it reaches an intersection or
     * dead-end. This function calls the update_surrounding_status.
     */
    void followSegment();


/*-----------------------------------------------------------------------------
 * Function name: auto_calibrate_line_sensors
 * Description: Assuming the robot is currently located on top of a black
 *              line on a white background (e.g., at the start of a maze-
 *              solving or line-following task), calling this function will
 *              have the robot rotate right and left to calibrate the line
 *              sensors.
 ----------------------------------------------------------------------------*/
    void auto_calibrate_line_sensors(int max_motor_speed);

/*-----------------------------------------------------------------------------
 * Function name: get_number_from_user
 * Description: This function obtains a positive number ( >0 ) from the user
 *              using a menu-based approach.
 * Output: int = user-specified number
 ----------------------------------------------------------------------------*/
    int get_number_from_user();

/*-----------------------------------------------------------------------------
 * Function name: get_song_from_user
 * Description: This function obtains a positive number ( >0 ) from the user
 *              using a menu-based approach.
 * Output: int = user-specified number
 ----------------------------------------------------------------------------*/
    int get_song_from_user();

    /*-----------------------------------------------------------------------------
 * Function name: get_tip_from_user
 * Description: This function obtains a positive number ( >0 ) from the user
 *              using a menu-based approach.
 * Output: int = user-specified number
 ----------------------------------------------------------------------------*/
    int get_tip_from_user();

    /*-----------------------------------------------------------------------------
* Function name: set_tip
* Description: This function obtains a positive number ( >0 ) from the user
*              using a menu-based approach.
* Output: int = user-specified number
----------------------------------------------------------------------------*/
    void print_tip();

    void set_tip(int t);


    bool lineToLeft() const { return mySensor.lineToLeft(); }

    bool lineAhead() const { return mySensor.lineAhead(); }

    bool lineToRight() const { return mySensor.lineToRight(); }

    bool atEnd() const { return mySensor.atEnd(); }


private:
/*-----------------------------------------------------------------------------
 * Function name: update_surrounding_status
 * Description: Reads the robot sensors to determine wheather
 *              there is black to the left, front, right, or the robot is at the
 *              end of the track (main station)
 */
    void update_surrounding_status();

    Sensors mySensor;
    unsigned int tip;
    char lastTurn{'S'};
};

#endif // ROBOT_H
