#ifndef AUTON_INTAKE_ARMS_H
#define AUTON_INTAKE_ARMS_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutonIntakeArms: public CommandBase
{
private:
	Timer* timer;
	double m_waitTime;
	bool m_bExtend;
public:
	AutonIntakeArms();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	void SetGoal(double timeout, bool extend) { m_waitTime = timeout, m_bExtend = extend; };
};

#endif
