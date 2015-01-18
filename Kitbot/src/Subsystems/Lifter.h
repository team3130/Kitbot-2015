#ifndef LIFTER_H
#define LIFTER_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Lifter: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Talon* m_cLiftMotor;
	DigitalInput* m_cLimitSwitchTop;
	DigitalInput* m_cLimitSwitchBot;
	double m_dLifterPosition;
	double m_dEncoderValue;
public:
	Encoder* m_cEncoder;
	Lifter();
	~Lifter();
	void InitDefaultCommand();
	void Balance(float direction);
	void moveLifter(float speed);
	bool GetLimitSwitchTop();
	bool GetLimitSwitchBot();

};

#endif
