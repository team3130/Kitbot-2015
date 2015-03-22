#ifndef AUTON_SMART_TURN_H
#define AUTON_SMART_TURN_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutonSmartTurn: public CommandBase
{
public:
	Timer cTimer;
	double dTimeout;
	double dAngle;
	double dDriveSpeed;
	double dDistGoal;
	AutonSmartTurn();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	void SetGoal(double angle, double timeout){
		dAngle = angle;
		dTimeout = timeout;
	}
};

#endif
