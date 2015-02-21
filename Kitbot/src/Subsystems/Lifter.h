#ifndef LIFTER_H
#define LIFTER_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Lifter: public Subsystem
{
private:
	CANTalon* m_cLiftMotor;
public:
	Lifter();
	~Lifter();
	void InitDefaultCommand();
	void toSetpoint(int goal);
	void moveLifter(float goal);
	bool GetLimitSwitchTop() { return m_cLiftMotor->GetForwardLimitOK(); };
	bool GetLimitSwitchBot() { return m_cLiftMotor->GetReverseLimitOK(); };
	double GetPosition() { return m_cLiftMotor->GetPosition(); };
	double GetSpeed() { return m_cLiftMotor->GetSpeed(); };
};

#endif
