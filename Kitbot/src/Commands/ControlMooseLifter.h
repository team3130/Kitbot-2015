#ifndef CONTROL_MOOSE_LIFTER_H
#define CONTROL_MOOSE_LIFTER_H

#include "../CommandBase.h"
#include "WPILib.h"

class ControlMooseLifter: public CommandBase
{
public:
	ControlMooseLifter();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
