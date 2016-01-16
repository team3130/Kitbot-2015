#ifndef EXAMPLE_SUBSYSTEM_H
#define EXAMPLE_SUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#define _USE_MATH_DEFINES
#include <math.h>

class ExampleSubsystem: public PIDSubsystem
{
	friend class RobotSensors;
private:
	const double WHEEL_DIAMATER = 6;
	bool m_bIsUsingGyro;
	bool m_bSquaredDrive;
	double moveSpeed;
//	Gyro* gyro;
	Encoder* m_cEncoderL;
	Encoder* m_cEncoderR;
public:
	RobotDrive m_drive;
	ExampleSubsystem();
	~ExampleSubsystem();
	void InitDefaultCommand();
	void Drive(double move, double turn, bool squaredInputs = false);
	double GetAngle();
	bool IsUsingGyro() {return m_bIsUsingGyro;};
	void HoldAngle(double angle = 0);
	void ReleaseAngle() { GetPIDController()->Disable(); m_bIsUsingGyro=false; };
	void GyroDrive(double move, bool squaredInputs = false);
	virtual double ReturnPIDInput();
	virtual void UsePIDOutput(double outputAngle);
	double GetDistance();
	void ResetEncoders();
};

#endif
