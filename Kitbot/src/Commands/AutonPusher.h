#ifndef AUTON_PUSHER_H
#define AUTON_PUSHER_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutonPusher: public CommandBase
{
private:
	Timer* timer;
	double m_waitTime;
	bool m_nDirection;
public:
	AutonPusher();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	void SetGoal(double timeout, int direction) { m_waitTime = timeout; m_nDirection = direction;};
};

#endif
