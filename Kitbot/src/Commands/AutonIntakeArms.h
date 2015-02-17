#ifndef AUTON_INTAKE_ARMS_H
#define AUTON_INTAKE_ARMS_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutonIntakeArms: public CommandBase
{
public:
	Timer* timer;
	double m_waitTime;
	AutonIntakeArms();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	void SetGoal(double timeout) { m_waitTime = timeout; };
};

#endif
