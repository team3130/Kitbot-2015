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
	Solenoid* m_cMoosePrevent;
	bool m_bActivated;
public:
	MooseLifter();
	~MooseLifter();
	void InitDefaultCommand();
	void MoveMooseLifterSolenoid();
	void MoveMooseLock(bool activated);

};

#endif
