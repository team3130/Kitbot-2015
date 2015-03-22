#ifndef AUTON_SMART_TURN_H
#define AUTON_SMART_TURN_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutonSmartTurn: public CommandBase
{
public:
	Timer m_cTimer;
	double m_dTimeout;
	double m_dAngle;
	double m_dDriveSpeed;
	double m_dDistGoal;
	AutonSmartTurn();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	void SetGoal(double angle, double timeout){
		m_dAngle = angle;
		m_dTimeout = timeout;
	}
};

#endif
