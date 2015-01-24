#ifndef DRIVE_STRAIGHT_GYRO_H
#define DRIVE_STRAIGHT_GYRO_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "../Subsystems/ExampleSubsystem.h"

class DriveStraightGyro: public PIDCommand{
private:
	Preferences* prefs;
	double np, ni, nd;
	double	moveSpeed;
	double	moveTurn;
	bool	gyroMode;
public:
	DriveStraightGyro(const char *name);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
	virtual double ReturnPIDInput();
	virtual void UsePIDOutput(double outputAngle);
};

#endif
