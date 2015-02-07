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
const int MOOSEPOSITIONSENSOR = 0;		//Change to Digital Input Output port 0
										//if available. Chris wired it there
const int DRIVE_ENCODERL_A = 4;
const int DRIVE_ENCODERL_B = 5;
const int DRIVE_ENCODERR_A = 6;
const int DRIVE_ENCODERR_B = 7;

//Lifter
// Really? These should be via TalonSRX
const int ENCODER_A = 12;
const int ENCODER_B = 13;


/****** Solenoids ************************/

const int INTAKEARML = 0;
const int INTAKEARMR = 1;
const int MOOSELIFTER = 2;
const int MOOSELOCK = 3;		//Controls Antlers Solenoid
const int MOOSEPREVENT = 4;		//Prevents Moose from going up any further


/****** CAN Channels *********************/

const int COMPRESSOR = 1;		//Controls compressor
const int LIFTER = 2;			//CANTalons CAN ports need to be assigned
const int PUSHER = 3;			//CANTalons CAN ports need to be assigned


/****** Analog Input channels ************/

const int C_GYRO = 0;


/****** Buttons and Axes *****************/

//lifters
const int A_LIFTER = 1;           //left thumbstick up and down
const int A_PUSHER = 4;			  //right thumbstick up and down
const int B_LIFTERGOAL1 = 1;
const int B_LIFTERGOAL2 = 2;
const int B_LIFTERGOAL3 = 3;

//intake
const int B_INTAKEROTATECCW = 5;   // left button on top of joystick
const int B_INTAKEIN = 2;		   // bottom button on top of joystick
const int B_INTAKEROTATECW = 4;    // right button on top of joystick
const int B_INTAKEOUT = 3;		   // top button on top of joystick


#endif
