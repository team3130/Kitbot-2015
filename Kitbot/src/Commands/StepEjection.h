#ifndef STEP_EJECTION_H
#define STEP_EJECTION_H

#include "../CommandBase.h"
#include "WPILib.h"

class StepEjection: public CommandBase
{
public:
	StepEjection();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
