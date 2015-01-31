#ifndef AUTON_ANTLER_MOOSE_H
#define AUTON_ANTLER_MOOSE_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutonAntlerMoose: public CommandBase
{
public:
	bool m_bAntlerMooseExecute;
	bool m_bLockDisabled;
	bool m_bRan;
	AutonAntlerMoose();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
