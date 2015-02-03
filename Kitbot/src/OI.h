#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI
{
private:

public:
	OI();
	Joystick*	stickL;
	Joystick*	stickR;
	Joystick*	gamepad;
	JoystickButton* LifterGoalToggle;
};

#endif
