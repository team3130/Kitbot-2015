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
const int LEFTMOTOR = 0;
const int RIGHTMOTOR = 1;

// Intake
const int INTAKEL = 2;
const int INTAKER = 3;

//Lifter
const int LIFTERL = 4;
const int LIFTERR = 5;
const int ENCODERL = 6;
const int ENCODERR = 7;

//buttons and axes

const int B_LIFTERUP = 6;
const int B_LIFTERDOWN = 7;
const int B_INTAKEIN = 8;
const int B_INTAKEOUT = 9;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
//const int RANGE_FINDER_PORT = 1;
//const int RANGE_FINDER_MODULE = 1;

#endif
