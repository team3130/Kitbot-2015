#ifndef INTAKE_H
#define INTAKE_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Intake: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	RobotDrive m_drive;
public:
	Intake();
	void InitDefaultCommand();
	void Drive(GenericHID *leftStick, GenericHID *rightStick, bool squaredInputs = true);
};

#endif
