#ifndef ANTLER_MOOSE_H
#define ANTLER_MOOSE_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class AntlerMoose: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Talon* m_cAntlerMooseMotor;
	DigitalInput* m_cAntlerLimitSwitchTop;
	DigitalInput* m_cAntlerLimitSwitchBot;
	double m_dLifterPosition;
	double m_dEncoderValue;
public:
	AntlerMoose();
	~AntlerMoose();
	void InitDefaultCommand();
	void Balance(float direction);
	void moveAntlerMoose(float speed);
	bool GetLimitSwitchTop();
	bool GetLimitSwitchBot();

};

#endif
