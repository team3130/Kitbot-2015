#ifndef ANTLER_MOOSE_H
#define ANTLER_MOOSE_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class AntlerMoose: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	DoubleSolenoid* m_cAntlerMooseLock;
	bool m_bActivated;

public:
	AntlerMoose();
	~AntlerMoose();
	void InitDefaultCommand();
	void MoveAntlerLock(bool status);
};

#endif
