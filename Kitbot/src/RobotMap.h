#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

/****** PWM ports ************************/

const int LEFTBACKMOTOR = 0;
const int RIGHTBACKMOTOR = 1;
const int LEFTFRONTMOTOR = 2;
const int RIGHTFRONTMOTOR = 3;
//Intake
const int INTAKER = 8;
const int INTAKEL = 9;


/****** Digital I/O **********************/

//Moose
const int MOOSEPOSITIONSENSOR = 0;

//Drive
const int PUSHER_LED = 1;
const int DRIVE_ENCODERL_A = 4;
const int DRIVE_ENCODERL_B = 5;
const int DRIVE_ENCODERR_A = 6;
const int DRIVE_ENCODERR_B = 7;


/****** Solenoids ************************/

const int INTAKEARML = 0;
const int INTAKEARMR = 1;
const int MOOSELIFTER = 2;
const int LEFTANTLER = 3;		//Controls left antler
const int MOOSEPREVENT = 4;		//Prevents Moose from going up any further
const int RIGHTANTLER = 5;		//Controls right antler



/****** CAN Channels *********************/

const int COMPRESSOR = 1;		//Controls compressor
const int LIFTER = 2;
const int PUSHER = 3;


/****** Analog Input channels ************/

const int C_GYRO = 0;


/****** Buttons and Axes *****************/

//lifters
const int A_LIFTER = 1;           //left thumbstick up and down
const int A_PUSHER = 3;			  //right thumbstick up and down
const int B_PAD_A = 2;		//Face buttons are for goals for lifter
const int B_PAD_B = 3;
const int B_PAD_X = 1;
const int B_PAD_Y = 4;

//intake

const int B_INTAKEROTATECCW = 5;   // right button on top of joystick
const int B_INTAKEIN = 2;		   // bottom button on top of joystick
const int B_INTAKEROTATECW = 4;    // left button on top of joystick
const int B_INTAKEOUT = 3;		   // top button on top of joystick

#endif
