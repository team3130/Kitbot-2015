#ifndef AUTON_SMART_TURN_H
#define AUTON_SMART_TURN_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutonSmartTurn: public CommandBase
{
public:
	Timer m_cTimer;
	Timer m_tCooldown;
	bool m_bConfirming;
	double m_dTimeout;
	double m_dTimeConfirm;
	double m_dAngle;
	double m_dDriveSpeed;
	double m_dDistGoal;
	double m_dTolerance;
	AutonSmartTurn();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	void SetGoal(double angle, double timeout, double tolerance=1.0, double confirm=0){
		m_dAngle = angle;
		m_dTimeout = timeout;
		m_dTolerance = tolerance;
		m_dTimeConfirm = confirm;
	}
};

#endif
