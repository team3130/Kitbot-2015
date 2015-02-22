#ifndef AUTON_DRIVE_H
#define AUTON_DRIVE_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "../Subsystems/ExampleSubsystem.h"

class AutonDriveStraight: public PIDCommand{
private:
	Timer timer;
	double speed;
	double goal;
	double threshold;
	double confirmTime;
public:
	AutonDriveStraight();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
	virtual double ReturnPIDInput();
	void SetGoal(double dist, double thresh=0.5, double ispeed=0.5, double timout=0);
	virtual void UsePIDOutput(double output);
};

#endif
