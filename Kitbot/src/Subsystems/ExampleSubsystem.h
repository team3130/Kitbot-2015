#ifndef EXAMPLE_SUBSYSTEM_H
#define EXAMPLE_SUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class ExampleSubsystem: public PIDSubsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	bool m_bIsUsingGyro;
	bool m_bSquaredDrive;
	double moveSpeed;
public:
	Gyro* gyro;
	Encoder* m_cEncoderL;
	Encoder* m_cEncoderR;
	RobotDrive m_drive;
	ExampleSubsystem();
	~ExampleSubsystem();
	void InitDefaultCommand();
	void Drive(double move, double turn, bool squaredInputs = true);
	double GetAngle() {return gyro->GetAngle();};
	void HoldAngle(double angle);
	void GyroDrive(double move, bool squaredInputs = true);
	virtual double ReturnPIDInput();
	virtual void UsePIDOutput(double outputAngle);

};

#endif
