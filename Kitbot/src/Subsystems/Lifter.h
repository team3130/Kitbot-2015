#ifndef LIFTER_H
#define LIFTER_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Lifter: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	CANTalon* m_cLiftMotor;
	double m_dLifterPosition;
	double m_dEncoderValue;
	bool m_bManualControl;
public:
	Encoder* m_cEncoder;
	Lifter();
	~Lifter();
	void InitDefaultCommand();
	void Balance(float direction);
	void moveLifter(float goal);
	bool GetLimitSwitchTop();
	bool GetLimitSwitchBot();
	void SwitchManualControl();
	bool GetManualControl();
	double GetEncoderValue();

};

#endif
