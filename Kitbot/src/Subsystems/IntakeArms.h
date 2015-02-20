#ifndef INTAKE_ARMS_H
#define INTAKE_ARMS_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class IntakeArms: public Subsystem
{
private:
	Solenoid* m_cIntakeSolenoidL;
	Solenoid* m_cIntakeSolenoidR;
public:
	IntakeArms();
	~IntakeArms();
	void InitDefaultCommand();
	void ControlArms(bool isExtendL, bool isExtendR);
};

#endif
