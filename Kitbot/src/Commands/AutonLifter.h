#ifndef AUTON_LIFTER_H
#define AUTON_LIFTER_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutonLifter: public CommandBase
{
private:
	Timer* timer;
	double m_waitTime;
	double m_dEncoderGoal;
public:
	AutonLifter();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	void SetGoal(double timeout, double goal) { m_waitTime = timeout; m_dEncoderGoal = goal;};
};

#endif
