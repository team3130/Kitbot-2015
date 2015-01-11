#ifndef LIFTER_H
#define LIFTER_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Lifter: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Talon* m_cLiftMotorL;
	Talon* m_cLiftMotorR;
	double m_dLifterPosition;
	double m_dEncoderLeftValue;
	double m_dEncoderRightValue;
public:
	DigitalInput* m_cLimitSwitch;
	Encoder* m_cEncoderL;
	Encoder* m_cEncoderR;
	Lifter();
	~Lifter();
	void InitDefaultCommand();
	bool getLimitSwitch(){return m_cLimitSwitch->Get();}
	double getLeftSpeed();
	double getRightSpeed();
	void Balance(float direction);
};

#endif
