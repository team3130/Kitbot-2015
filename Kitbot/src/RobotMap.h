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

//Intake
const int INTAKER = 2;
const int INTAKEL = 3;

//Lifter
const int LIFTERL = 4;
const int LIFTERR = 5;
const int ENCODERL_A = 6;
const int ENCODERL_B = 7;
const int ENCODERR_A = 8;
const int ENCODERR_B = 9;
const int LIFTERSWITCH = 10;

//Bin Lifter
const int BINLIFTER = 11;

////buttons and axes
//buttons lifters
const int A_LIFTER = 4;           //right thumbstick

//buttons intake
const int B_INTAKEROTATECCW = 1;   // x button
const int B_INTAKEIN = 2;		   // a button
const int B_INTAKEROTATECW = 3;    // y button
const int B_INTAKEOUT = 4;		   // b button

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
//const int RANGE_FINDER_PORT = 1;
//const int RANGE_FINDER_MODULE = 1;

#endif
