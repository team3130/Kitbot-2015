#ifndef MOOSE_LIFTER_H
#define MOOSE_LIFTER_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class MooseLifter: public Subsystem
{
private:
	DigitalInput* m_cMoosePositionSensor;
	Solenoid* m_cMooseSolenoid;
	Solenoid* m_cMoosePrevent;
	bool m_bActivated;
public:
	MooseLifter();
	~MooseLifter();
	void InitDefaultCommand();
	void MoveMooseLifterSolenoid(bool pushUp);
	void MoveMooseLock(bool stopMoving);
	bool isHighEnough() { return !m_cMoosePositionSensor->Get(); };
	bool isUp() { return m_bActivated; };
};

#endif
