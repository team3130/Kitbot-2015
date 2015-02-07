#ifndef LIFTER_H
#define LIFTER_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Lifter: public PIDSubsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	double m_dLifterPosition;
	double m_dEncoderValue;
	bool m_bIsCalibrated;
	CANTalon* m_cLiftMotor;
public:
	Lifter();
	~Lifter();
	void InitDefaultCommand();
	void moveLifter(float goal);
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	bool GetLimitSwitchTop();
	bool GetLimitSwitchBot();
	double GetPosition();
};

#endif
