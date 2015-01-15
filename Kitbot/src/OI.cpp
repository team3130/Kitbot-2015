#include "OI.h"
#include "Commands/DriveStraightGyro.h"

OI::OI()
{
	stickL = new Joystick(0);
	stickR = new Joystick(1);
	gamepad = new Joystick(2);
	rightPrecision = new JoystickButton(stickR, 1);
	rightPrecision->WhenPressed(new DriveStraightGyro("Test Gyro"));
}
