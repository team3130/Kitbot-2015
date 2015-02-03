#include "OI.h"
#include "Commands/DriveStraightGyro.h"
#include "Commands/ToggleLifterGoal"

OI::OI()
{
	stickL = new Joystick(0);
	stickR = new Joystick(1);
	gamepad = new Joystick(2);
	LifterGoalToggle = new JoystickButton(gamepad, 9);
	LifterGoalToggle->WhenPressed(new ToggleLifterGoal());
}
