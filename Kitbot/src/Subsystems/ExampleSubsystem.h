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
	Encoder* m_cEncoderUL;
	Encoder* m_cEncoderUR;
	Encoder* m_cEncoderLL;
	Encoder* m_cEncoderLR;
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

};

#endif
