#ifndef AUTON_LIFTER_H
#define AUTON_LIFTER_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutonLifter: public CommandBase
{
public:
	bool m_bLifterExecute;
	int m_nLifterDirection;
	AutonLifter();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
