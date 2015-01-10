#ifndef CONTROL_ROLLERS_H
#define CONTROL_ROLLERS_H

#include "../CommandBase.h"
#include "WPILib.h"

class ControlRollers: public CommandBase
{
public:
	int intakeStatus;
	ControlRollers();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
