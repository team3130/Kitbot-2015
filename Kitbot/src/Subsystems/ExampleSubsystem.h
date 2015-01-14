#ifndef EXAMPLE_SUBSYSTEM_H
#define EXAMPLE_SUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class ExampleSubsystem: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	RobotDrive m_drive;
	bool m_bIsUsingGyro;
public:
	Gyro* gyro;
	ExampleSubsystem();
	~ExampleSubsystem();
	bool CanUseGyro();
	void InitDefaultCommand();
	void Drive(GenericHID *leftStick, GenericHID *rightStick, bool squaredInputs = true);
};

#endif
