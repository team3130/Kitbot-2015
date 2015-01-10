#ifndef LIFTER_H
#define LIFTER_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Lifter: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Encoder m_cEncoderL;
	Encoder m_cEncoderR;
	DigitalInput m_cLimitSwitch;
	SpeedController m_cLiftMotorL;
	SpeedController m_cLiftMotorR;
	float m_fRateDifference = 0;
public:
	Lifter();
	void InitDefaultCommand();
	void Move(GenericHID *gamepad);
};

#endif
