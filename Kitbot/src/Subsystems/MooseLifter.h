#ifndef MOOSE_LIFTER_H
#define MOOSE_LIFTER_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class MooseLifter: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Jaguar* m_cMooseLiftMotor;
	DigitalInput* m_cMooseLimitSwitchTop;
	DigitalInput* m_cMooseLimitSwitchBot;
	Solenoid* m_cMooseSolenoid;
	double m_dMooseLifterPosition;
	double m_dEncoderValue;
public:
	MooseLifter();
	~MooseLifter();
	void InitDefaultCommand();
	void Balance(float direction);
	void MoveMooseLifterMotor(float speed);
	void MoveMooseLifterSolonoid(float direction);
	bool GetLimitSwitchTop();
	bool GetLimitSwitchBot();

};

#endif
