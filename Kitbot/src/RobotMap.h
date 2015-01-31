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
const int LEFTBACKMOTOR = 0;
const int RIGHTBACKMOTOR = 1;
const int LEFTFRONTMOTOR = 2;
const int RIGHTFRONTMOTOR = 3;
const int DRIVE_ENCODERL_A = 4;
const int DRIVE_ENCODERL_B = 5;
const int DRIVE_ENCODERR_A = 6;
const int DRIVE_ENCODERR_B = 7;

//Intake
const int INTAKER = 8;
const int INTAKEL = 9;
const int INTAKEARMS = 0;		//Solenoid

//Lifter
const int LIFTER = 10;
const int PUSHER = 11;
const int ENCODER_A = 12;
const int ENCODER_B = 13;
const int LIFTERSWITCHBOT = 14;
const int LIFTERSWITCHTOP = 15;
const int LIFTERSWITCHIN = 16;
const int LIFTERSWITCHOUT = 17;

//Moose
const int MOOSELIFTER = 1;		//Solenoid
const int MOOSELOCK = 2;		//Solenoid
const int MOOSELIFTERSWITCHTOP = 18;
const int MOOSELIFTERSWITCHBOT = 19;
const int ANTLERMOOSESWITCHTOP = 20;
const int ANTLERMOOSESWITCHBOT = 21;

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
const int B_MOOSELIFTERUP = 8;		//right trigger
const int B_MOOSELIFTERDOWN = 6;	//right bumper
const int B_ANTLERMOOSEUP = 7;		//left trigger
const int B_ANTLERMOOSEDOWN = 5;	//left bumper

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
//const int RANGE_FINDER_PORT = 1;
//const int RANGE_FINDER_MODULE = 1;

#endif
