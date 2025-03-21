#ifndef AUTON_TURNER_H
#define AUTON_TURNER_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutonTurn: public CommandBase
{
private:
	Timer* timer;
	double m_angle;
	double m_threshold;
	double m_waitTime;
public:
	AutonTurn();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	void SetGoal(double angle, double thresh, double timeout) { m_angle = angle,
																m_threshold = thresh,
																m_waitTime = timeout; };
};

#endif
