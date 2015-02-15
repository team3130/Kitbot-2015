#ifndef ANTLER_MOOSE_H
#define ANTLER_MOOSE_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class AntlerMoose: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Solenoid* m_cLeftAntler;
	Solenoid* m_cRightAntler;
	bool m_bLeftDown;
	bool m_bRightDown;
public:
	AntlerMoose();
	~AntlerMoose();
	void InitDefaultCommand();
	void ControlLeftAntler(bool downLeft);
	void ControlRightAntler(bool downRight);
	bool IsLeftDown(){return m_bLeftDown;};
	bool IsRightDown(){return m_bRightDown;};
};

#endif
