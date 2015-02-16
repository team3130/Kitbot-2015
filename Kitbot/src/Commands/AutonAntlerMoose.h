#ifndef AUTON_ANTLER_MOOSE_H
#define AUTON_ANTLER_MOOSE_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutonAntlerMoose: public CommandBase
{
public:
	Timer* timer;
	double m_waitTime;
	AutonAntlerMoose();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	void SetGoal(double timeout) { m_waitTime = timeout; };
};

#endif
