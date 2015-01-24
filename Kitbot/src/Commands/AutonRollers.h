#ifndef AUTON_ROLLERS_H
#define AUTON_ROLLERS_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutonRollers: public CommandBase
{
public:
	int m_nLeftIntake;
	int m_nRightIntake;
	bool m_bRollersExecute;
	int m_nTimer;
	AutonRollers();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
