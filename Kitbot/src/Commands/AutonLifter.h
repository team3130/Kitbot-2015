#ifndef AUTON_LIFTER_H
#define AUTON_LIFTER_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "../Subsystems/Lifter.h"

class AutonLifter: public PIDCommand{
private:
	Timer* timer;
	double m_waitTime;
	double m_dThreshold;
	double m_dEncoderGoal;
public:
	AutonLifter();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
	virtual double ReturnPIDInput();
	void SetGoal(double timeout, double thresh, double goal);
	virtual void UsePIDOutput(double output);
};

#endif
