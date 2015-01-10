#ifndef LIFTER_H
#define LIFTER_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Lifter: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	DigitalInput* m_cLimitSwitch;
	Talon* m_cLiftMotorL;
	Talon* m_cLiftMotorR;
	double m_dRateDifference;
	double m_dlifterPosition;
public:
	Encoder* m_cEncoderL;
	Encoder* m_cEncoderR;
	Lifter();
	~Lifter();
	void InitDefaultCommand();
	void SetDirection(int direction);
};

#endif
