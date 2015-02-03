#ifndef MOOSE_LIFTER_H
#define MOOSE_LIFTER_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class MooseLifter: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	DigitalInput* m_cMoosePositionSensor;
	Solenoid* m_cMooseSolenoid;
	Solenoid* m_cMooseLock;
public:
	MooseLifter();
	~MooseLifter();
	void InitDefaultCommand();
	void MoveMooseLifterSolenoid(bool direction);
	void MoveMooseLock(bool activated);

};

#endif
