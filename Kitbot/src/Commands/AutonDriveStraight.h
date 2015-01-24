#ifndef AUTON_DRIVE_H
#define AUTON_DRIVE_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "../Subsystems/ExampleSubsystem.h"

class AutonDriveStraight: public PIDCommand{
private:
	double	moveSpeed;
	double	moveTurn;
	bool m_bUpdateTimer;
public:
	bool m_bExecute;
	int m_nTimer;
	int m_nDrivePowerR;
	int m_nDrivePowerL;
	bool gyroMode;
	AutonDriveStraight();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
	virtual double ReturnPIDInput();
	virtual void UsePIDOutput(double outputAngle);
	void UpdateTimer(int TimerVal);
};

#endif
