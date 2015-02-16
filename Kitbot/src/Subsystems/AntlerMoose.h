#ifndef ANTLER_MOOSE_H
#define ANTLER_MOOSE_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class AntlerMoose: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	DoubleSolenoid* m_cLeftAntler;
	DoubleSolenoid* m_cRightAntler;
	bool m_bLeftAntlerDown;
	bool m_bRightAntlerDown;
public:
	AntlerMoose();
	~AntlerMoose();
	void InitDefaultCommand();
	void ControlLeftAntler(DoubleSolenoid::Value leftStatus);
	void ControlRightAntler(DoubleSolenoid::Value rightStatus);
	bool IsLeftAntlerDown(){return m_bLeftAntlerDown;};
	bool IsRightAntlerDown(){return m_bRightAntlerDown;};
};

#endif
