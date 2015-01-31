#ifndef AUTON_MOOSE_LIFTER_H
#define AUTON_MOOSE_LIFTER_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutonMooseLifter: public CommandBase
{
public:
	bool m_bMooseExecute;
	bool m_bMooseOn;
	AutonMooseLifter();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
