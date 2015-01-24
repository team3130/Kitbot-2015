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
	Talon* m_cPushMotor;
	DigitalInput* m_cLimitSwitchTop;
	DigitalInput* m_cLimitSwitchBot;
	DigitalInput* m_cLimitSwitchIn;
	DigitalInput* m_cLimitSwitchOut;
	double m_dLifterPosition;
	double m_dEncoderValue;
public:
	Encoder* m_cEncoder;
	Lifter();
	~Lifter();
	void InitDefaultCommand();
	void Balance(float direction);
	void moveLifter(float speed);
	void pushLifter(float speed);
	bool GetLimitSwitchTop();
	bool GetLimitSwitchBot();
	bool GetLimitSwitchIn();
	bool GetLimitSwitchOut();

};

#endif
