#ifndef AUTON_DUMB_TURN_H
#define AUTON_DUMB_TURN_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutonDumbTurn: public CommandBase
{
private:
	double m_waitTime;
	double m_driveTurn;
	Timer* timer;
public:
	AutonDumbTurn();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	void SetGoal(double turn, double timeout) { m_driveTurn = turn; m_waitTime = timeout; };
};

#endif
