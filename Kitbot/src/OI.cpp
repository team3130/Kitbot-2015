#include "OI.h"
#include "Commands/DriveStraightGyro.h"
#include "Commands/JoystickVideo.h"

OI::OI()
{
	stickL = new Joystick(0);
	stickR = new Joystick(1);
	gamepad = new Joystick(2);
	rightPrecision = new JoystickButton(stickR, 2);
	rightPrecision->WhenPressed(new JoystickVideo("Test Video"));
}
