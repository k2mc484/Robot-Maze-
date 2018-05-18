/*Use this file to implement functions related to the robot*/

#include "robot_utils.h"
#include <pololu/3pi.h>   /* allow use of 3pi robot functions */
#include <stdlib.h>

void print_two_lines(const char * const line1, const char * const line2) {
    /* clear lcd */
    clear();

    /* print first line */
    lcd_goto_xy(0, 0);
    print(line1);

    /* print second line */
    lcd_goto_xy(0, 1);
    print(line2);
}




