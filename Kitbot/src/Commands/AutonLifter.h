#ifndef AUTON_LIFTER_H
#define AUTON_LIFTER_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutonLifter: public CommandBase
{
public:
	bool m_bLifterExecute;
	bool m_b2StageOn;
	bool m_bStage1Done;
	bool m_bStage2Done;
	AutonLifter();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
