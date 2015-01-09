#include "OI.h"

OI::OI()
{
	stickL = new Joystick(0);
	stickR = new Joystick(1);
	gamepad = new Joystick(2);
}
