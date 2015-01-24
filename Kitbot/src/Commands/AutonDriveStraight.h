#ifndef DRIVE_STRAIGHT_GYRO_H
#define DRIVE_STRAIGHT_GYRO_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "../Subsystems/ExampleSubsystem.h"

class DriveStraightGyro: public PIDCommand{
private:
	double	moveSpeed;
	double	moveTurn;
public:
	bool execute = false;
	int m_nTimer = 0;
	int m_nDrivePowerR = 0;
	int m_nDrivePowerL = 0;
	bool gyroMode;
	DriveStraightGyro();
	DriveStraightGyro(float fL, float fR);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
	virtual double ReturnPIDInput();
	virtual void UsePIDOutput(double outputAngle);
};

#endif
