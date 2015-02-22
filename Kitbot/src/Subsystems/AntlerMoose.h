#ifndef ANTLER_MOOSE_H
#define ANTLER_MOOSE_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class AntlerMoose: public Subsystem
{
private:
	Solenoid* m_cLeftAntler;
	Solenoid* m_cRightAntler;
	bool m_bLeftAntlerDown;
	bool m_bRightAntlerDown;
public:
	AntlerMoose();
	~AntlerMoose();
	void InitDefaultCommand();
	void ControlLeftAntler(bool Up);
	void ControlRightAntler(bool Up);
	bool IsLeftAntlerDown(){return m_bLeftAntlerDown;};
	bool IsRightAntlerDown(){return m_bRightAntlerDown;};
};

#endif
