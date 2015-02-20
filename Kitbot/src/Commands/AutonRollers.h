#ifndef AUTON_ROLLERS_H
#define AUTON_ROLLERS_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutonRollers: public CommandBase
{
private:
	Timer* timer;
	double m_waitTime;
	int m_nLeftIntake;
	int m_nRightIntake;
public:
	AutonRollers();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	void SetGoal(double timeout, double leftStatus, double rightStatus){
		m_waitTime = timeout, m_nLeftIntake = leftStatus, m_nRightIntake = rightStatus;};
};

#endif
