#ifndef AUTON_MOOSE_LIFTER_H
#define AUTON_MOOSE_LIFTER_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutonMooseLifter: public CommandBase
{
private:
	double m_waitTime;
	double m_distance;
	bool m_bMooseUp;
	bool m_bDone;
	Timer* timer;
public:
	AutonMooseLifter();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	void SetGoal(double dist, double timeout, bool is_up) {m_distance=dist; m_waitTime=timeout; m_bMooseUp=is_up;};
};

#endif
