#include "OI.h"
#include "Commands/DriveStraightTest.h"

OI::OI()
{
	stickL = new Joystick(0);
	stickR = new Joystick(1);
	gamepad = new Joystick(2);
	straightTest = new JoystickButton(stickR, 10);
	straightTest->WhenPressed(new DriveStraightTest());
}
