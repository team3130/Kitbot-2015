#ifndef TOGGLE_LIFTER_GOAL_H
#define TOGGLE_LIFTER_GOAL_H

#include "../CommandBase.h"
#include "WPILib.h"

class ToggleLifterGoal: public CommandBase
{
public:
	ToggleLifterGoal();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
