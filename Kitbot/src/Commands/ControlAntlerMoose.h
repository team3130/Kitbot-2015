#ifndef CONTROL_ANTLER_MOOSE_H
#define CONTROL_ANTLER_MOOSE_H

#include "../CommandBase.h"
#include "WPILib.h"

class ControlAntlerMoose: public CommandBase
{
public:
	bool m_bRan;
	bool m_bAntlerLockOn;
	ControlAntlerMoose();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
