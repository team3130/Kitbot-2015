#ifndef ROBOTMAP_H
#define ROBOTMAP_H

#include "WPILib.h"

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
 
// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
//Drive Train/Chassis
const int LEFTMOTOR = 0;
const int RIGHTMOTOR = 1;
const int DRIVE_ENCODERL_A = 12;
const int DRIVE_ENCODERL_B = 13;
const int DRIVE_ENCODERR_A = 14;
const int DRIVE_ENCODERR_B = 15;

//Intake
const int INTAKER = 2;
const int INTAKEL = 3;
const int INTAKEARMS = 9;

//Lifter
const int LIFTER = 4;
const int PUSHER =23;
const int ENCODER_A = 5;
const int ENCODER_B = 6;
const int LIFTERSWITCHBOT = 7;
const int LIFTERSWITCHTOP = 8;
const int LIFTERSWITCHIN = 21;
const int LIFTERSWITCHOUT = 22;

//Moose
const int MOOSELIFTER = 10;
const int MOOSELOCK = 11;
const int MOOSELIFTERSWITCHTOP = 16;
const int MOOSELIFTERSWITCHBOT = 17;
const int ANTLERMOOSESWITCHTOP = 18;
const int ANTLERMOOSESWITCHBOT = 19;

// Analog Input channels
const int C_GYRO = 0;

////buttons and axes
//lifters
const int A_LIFTER = 1;           //right thumbstick
const int A_PUSHER = 2;			  //left thumbstick

//intake
const int B_INTAKEROTATECCW = 1;   // x button
const int B_INTAKEIN = 2;		   // a button
const int B_INTAKEROTATECW = 3;    // y button
const int B_INTAKEOUT = 4;		   // b button

//MooseLifter
const int B_MOOSELIFTERUP = 8;
const int B_MOOSELIFTERDOWN = 6;
const int B_ANTLERMOOSEUP = 7;
const int B_ANTLERMOOSEDOWN = 5;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
//const int RANGE_FINDER_PORT = 1;
//const int RANGE_FINDER_MODULE = 1;

#endif
