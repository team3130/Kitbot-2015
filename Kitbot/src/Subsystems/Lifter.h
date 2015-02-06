#ifndef LIFTER_H
#define LIFTER_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Lifter: public PIDSubsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	CANTalon* m_cLiftMotor;
	double m_dLifterPosition;
	double m_dEncoderValue;
	bool m_bIsCalibrated;
public:
	Lifter();
	~Lifter();
	void InitDefaultCommand();
	void Balance(float direction);
	void moveLifter(float goal);
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void Calibrate(double setpoint);
	void SetLifterDirect(double goal);
	void ProjectSensors();
	void SetGoalInches(double inches);
	bool GetLimitSwitchTop();
	bool GetLimitSwitchBot();
};

#endif
