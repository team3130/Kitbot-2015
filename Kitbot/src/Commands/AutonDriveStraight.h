#ifndef AUTON_DRIVE_H
#define AUTON_DRIVE_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "../Subsystems/ExampleSubsystem.h"

class AutonDriveStraight: public PIDCommand{
private:
	bool m_bGyroPrep;
	bool m_bGyroMode;
	Timer m_cGyroTimer;
public:
	bool m_bExecute;
	Timer timer;
	double speed;
	double goal;
	double threshold;
	double confirmTime;
	double dumbDriveTime;
	double keepAngle;
	bool isConfirming;
	bool gyroMode;
	AutonDriveStraight();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
	virtual double ReturnPIDInput();
	void SetGoal(double dist, double thresh=0, double timeToWait=0, double ispeed=1);
	virtual void UsePIDOutput(double output);
};

#endif
