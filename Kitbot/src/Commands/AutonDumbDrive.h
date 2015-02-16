#ifndef AUTON_DUMB_DRIVE_H
#define AUTON_DUMB_DRIVE_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutonDumbDrive: public CommandBase
{
public:
	Timer* timer;
	double m_waitTime;
	AutonDumbDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	void SetGoal(double timeout) { m_waitTime = timeout; };
};

#endif
