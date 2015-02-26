#ifndef AUTON_DUMB_TURN_H
#define AUTON_DUMB_TURN_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutonDumbTurn: public CommandBase
{
private:
	Timer* timer;
	double m_driveTurn;
	double m_waitTime;
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
