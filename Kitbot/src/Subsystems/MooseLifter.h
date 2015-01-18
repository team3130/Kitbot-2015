#ifndef MOOSE_LIFTER_H
#define MOOSE_LIFTER_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class MooseLifter: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Talon* m_cMooseLiftMotor;
	DigitalInput* m_cLimitSwitchTop;
	DigitalInput* m_cLimitSwitchBot;
	Solenoid* m_cMooseSolonoid;
	double m_dLifterPosition;
	double m_dEncoderValue;
public:
	MooseLifter();
	~MooseLifter();
	void InitDefaultCommand();
	void Balance(float direction);
	void moveMooseLifter(float speed);
	bool GetLimitSwitchTop();
	bool GetLimitSwitchBot();

};

#endif
