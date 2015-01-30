#ifndef AUTON_ANTLER_MOOSE_H
#define AUTON_ANTLER_MOOSE_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutonAntlerMoose: public CommandBase
{
public:
	bool b_AntlerMooseExecute;
	bool b_LockDisabled;
	AutonAntlerMoose();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
