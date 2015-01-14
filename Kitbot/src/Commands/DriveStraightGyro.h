#ifndef DRIVE_STRAIGHT_GYRO_H
#define DRIVE_STRAIGHT_GYRO_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "../Subsystems/ExampleSubsystem.h"

class DriveStraightGyro: public PIDCommand{
private:
	const float m_dKp = 0.1; //arbitrary constant to correct turning
	Timer timer;
	double goalTime;
	double moveSpeed;
	ExampleSubsystem* chassis;	//from commandbase. we aren't a subclass of it b/c of deadly diamond of death
public:
	DriveStraightGyro(const char *name);
	void SetGoal(double time, double speed);
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
	virtual double ReturnPIDInput();
	virtual void UsePIDOutput();
};

#endif
