#ifndef AUTON_ANTLER_MOOSE_H
#define AUTON_ANTLER_MOOSE_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutonAntlerMoose: public CommandBase
{
public:
	Timer* timer;
	bool m_bAntlerMooseExecute;
	bool m_bRan;
	AutonAntlerMoose();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
