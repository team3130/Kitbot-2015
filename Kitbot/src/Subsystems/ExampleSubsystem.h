#ifndef EXAMPLE_SUBSYSTEM_H
#define EXAMPLE_SUBSYSTEM_H

#include "Commands/Subsystem.h"
#include "WPILib.h"
#define _USE_MATH_DEFINES
#include <math.h>

/*const double WHEEL_DIAMATER = 6;
const double DRIVE_ENCODER_PPR = 256;*/

class ExampleSubsystem: public PIDSubsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	double np, ni, nd;
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
	bool IsUsingGyro() {return m_bIsUsingGyro;};
	void HoldAngle(double angle = 0);
	void GyroDrive(double move, bool squaredInputs = true);
	virtual double ReturnPIDInput();
	virtual void UsePIDOutput(double outputAngle);
	double GetDistance();
};

#endif
