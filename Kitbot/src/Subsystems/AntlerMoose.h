#ifndef ANTLER_MOOSE_H
#define ANTLER_MOOSE_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class AntlerMoose: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	Solenoid* m_cAntlerMooseLock;
	AntlerMoose();
	~AntlerMoose();
	void InitDefaultCommand();
	void MoveAntlerLock(bool activated);
};

#endif
