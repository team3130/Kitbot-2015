#ifndef CONTROL_BIN_INTAKE_H
#define CONTROL_BIN_INTAKE_H

#include "../CommandBase.h"
#include "WPILib.h"

class ControlBinIntake: public CommandBase
{
public:
	ControlBinIntake();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
