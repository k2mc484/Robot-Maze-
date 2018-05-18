
/*------------------------------------------------------------------------------
 * Programmers: Jordan Mitchell & Kyle Hall
 * Name: hw3.cpp
 * Description: The user chooses a cubicle and a song to play. After the user enters these values, the robot is sent to the
 * specified terminal by calling the sendRobotToTerminal function. If the terminal is reached then the chosen song is
 * played. Once the song is done playing then the robot return the the start. Now the robot is ready to repeat this
 * process again.
 -------------------------------------------------------------------------------*/
#include <pololu/3pi.h>   /* allow use of 3pi robot functions */
#include <avr/pgmspace.h> /* allow use of program space */
#include "robot.h"
#include "robotMovement.h"
#include "robot_utils.h"

const char yourMUSIC[] PROGMEM = "T500>d-2r8>d-r16>d-r16>d-r16>d-r8r8r8";
const char ready[] PROGMEM = "T500>d-d-r16>d-r8r8r8";
const char onIowa[] PROGMEM = "T500>d-2r8>d-r16>d-r16>d-r16>d-r16>d>d>d>d>d>dr8r8r8 >d-2r8>d-r16>d-r16>d-r16>d-r16>f>f>f>f>f>fr8r8r8>f>f>fr16r16r16>e>e>er16r16r16>e->e->e-r16r16r16>d>d>dr16r16r16 >d->d->d->d->d->d-r8r8r8>c>c>cr16r16r16b-b-b-r16r16r16a-a-r8b-r16>c>cr8b-r16a-a-a-a-a-a-r8r8r8";
const char hbd[] PROGMEM = "T200d4d4e2d2g2f+.r16 d4d4e2d2a2g.r16 d4d4>d2b2g2f+4e2>c4>c4b2g2a2g.";
// the first few measures of Bach's fugue in D-minor
const char fugue[] PROGMEM = "!T240 L8 a gafaeada c+adaeafa >aa>bac#ada c#adaeaf4";

int main(void) {
    //Declare variables
    int terminalFound = 0;
    int mainFound = 0;
    //Create robot with the default constructor
    Robot robot = Robot();

    /* perform battery check before starting */
    robot.bat_check();
    robot.auto_calibrate_line_sensors(40);

    while (1) {
        /*Get cubicle number from the user*/
        int dest = robot.get_number_from_user();
        /*comment this followSegment call when you start working on your own code*/
        //robot.followSegment();

        /*TODO: Ask the user to select to song*/
        int song = robot.get_song_from_user();
        /*TODO: Send robot to the specified terminal calling function sendRobotToTerminal */
        terminalFound = sendRobotToTerminal(&robot, dest);
        /*TODO: If terminal is reached, play the chosen song */
        if (terminalFound == 1) {
            if (song == 1) {
                //Play the first song to completion.
                play_from_program_space(yourMUSIC);
                while (is_playing()) { ;
                }
            }
            if (song == 2) {
                //Play the second song to completion.

                play_from_program_space(ready);
                while (is_playing()) { ;
                }
            }
            if (song == 3) {
                //Play the third song to completion.

                play_from_program_space(onIowa);
                while (is_playing()) { ;
                }
            }
            if (song == 4) {
                //Play the fourth song to completion.

                play_from_program_space(hbd);
                while (is_playing()) { ;
                }
            }
            if (song == 5) {
                //Play the fifth song to completion.

                play_from_program_space(fugue);
                while (is_playing()) { ;
                }
            }
            //Ask for tip
            robot.set_tip(robot.get_tip_from_user());
        }

        /*TODO: Return robot to main station calling function returnToStart */
        mainFound = returnToStart(&robot);
        if (mainFound == 1) {
            robot.print_tip();
        } else {
            clear();
            lcd_goto_xy(1, 0);
            print("LOST");
            delay_ms(500);
            clear();
        }

    }

}
