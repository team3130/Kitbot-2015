#include "OI.h"
#include "Commands/DriveStraightGyro.h"
#include "Commands/ResetLifter.h"
#include "Commands/ControlMooseLifter.h"
#include "Commands/ControlAntlerMoose.h"

OI::OI()
{
	stickL = new Joystick(0);
	stickR = new Joystick(1);
	gamepad = new Joystick(2);
}
