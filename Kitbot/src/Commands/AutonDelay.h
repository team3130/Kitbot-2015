#ifndef AUTON_DELAY_H
#define AUTON_DELAY_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutonDelay: public CommandBase
{
private:
	Timer* timer;
	double m_waitTime;
public:
	AutonDelay();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	void SetWait(double timeout);
};

#endif
