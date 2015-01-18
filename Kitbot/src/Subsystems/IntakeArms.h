#ifndef INTAKE_ARMS_H
#define INTAKE_ARMS_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class IntakeArms: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Solenoid* m_cIntakeControl;
public:
	IntakeArms();
	~IntakeArms();
	void InitDefaultCommand();
	void ControlArms(bool isExtend);
};

#endif
