#include "OI.h"
#include "Commands/DriveStraightGyro.h"
#include "Commands/JoystickVideo.h"
#include "Commands/ResetLifter.h"
#include "Commands/ControlMooseLifter.h"
#include "Commands/ControlAntlerMoose.h"

OI::OI()
{
	stickL = new Joystick(0);
	stickR = new Joystick(1);
	gamepad = new Joystick(2);
	VideoTest         = new JoystickButton(stickR, 6);
	MooseLifterToggle = new JoystickButton(gamepad, 8);
	AntlerMooseToggle = new JoystickButton(gamepad, 7);
	MooseLifterToggle->WhenReleased(new ControlMooseLifter());
	AntlerMooseToggle->WhenReleased(new ControlAntlerMoose());
	VideoTest->WhenPressed(new JoystickVideo("Test Video"));
}
