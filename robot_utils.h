#ifndef ROBOT_UTILS_H
#define ROBOT_UTILS_H

#include <pololu/3pi.h>   /* allow use of 3pi robot functions */
#include <avr/pgmspace.h> /* allow use of program space */

#define MAX_NUM_SENSORS 5          /**< The number of sensors for the robot */


/**************************************************************
* @brief The storage type for bar code numbers
 **************************************************************/
typedef unsigned char BarcodeType;

/**************************************************************
* @brief Location of robot sensors
 **************************************************************/
enum SensorPlacementEnum
{
  S_FARLEFT = 0,  /**< Far left sensor index */
  S_LEFT = 1,     /**< left sensor index */
  S_CENTER = 2,   /**< center sensor index */
  S_RIGHT = 3,    /**< right sensor index */
  S_FARRIGHT = 4  /**< Far right sensor index */
};

typedef enum SensorPlacementEnum SensorPlacement;

/**************************************************************
* @brief The type of segment found:
 **************************************************************/

/*
* @brief The enumeration for type of segment found
*/
enum SegmentEnum
{
  SEGMENT_INVALID = 0,
  SEGMENT_DEADEND = 1,
  SEGMENT_INTERSECTION = 2
};

/**
* @brief  typedef for the enumeration of segment found
 ***/
typedef enum SegmentEnum SegmentType;

/**************************************************************
* @brief Location of robot sensors
 **************************************************************/

/**************************************************************
* @brief A structure to represent the sensor array for 3pi robot
*
* This structure holds both the current sensor array readings and
* a construct for holding the previous location memory of a 3pi
* robot
**************************************************************/
struct RobotSensorsArrayTypeStruct
{
  unsigned int mazeSensors[MAX_NUM_SENSORS];             /**< Get current sensor
                                                            readings ahead of
                                                            robot */
  unsigned int mazeSensorsPreviousRead[MAX_NUM_SENSORS]; /**< Store last sensor
                                                            readings */
};

/**
* @brief Type of the robot sensors array
*/
typedef struct RobotSensorsArrayTypeStruct RobotSensorsArrayType;

/**************************************************************
* @brief Move actions that the robot can take
*
* Note that 'l' us an 8bit char in ASCII representing a number.
 **************************************************************/
enum MoveActionsTypeEnum
{
  MV_STRAIGHT = 's', /**< Move straight */
  MV_LEFT = 'l',     /**< Move left */
  MV_RIGHT = 'r',    /**< Move right */
  MV_UTURN = 'u',    /**< Move uturn */
  MV_INVALID = 0     /**< An invalid motion, helpful for debugging */
};
typedef enum MoveActionsTypeEnum MoveActionsType; /**< Move actions that the
                                                     robot can take */


/*-----------------------------------------------------------------------------
 * Function name: print_two_lines
 * Description: This function clears the LCD and prints the string given by
 *              line1 on the first line and the string given by line2 on the
 *              second line.
 * Inputs: line1 = const char * = string to be displayed on first line
 *         line2 = const char * = string to be displayed on second line
 ----------------------------------------------------------------------------*/
extern void print_two_lines(const char * const line1, const char * const line2);



#endif //ROBOT_UTILS_H
