#ifndef AUTONOMOUS_GROUP_6_H
#define AUTONOMOUS_GROUP_6_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "AutonDriveStraight.h"
#include "AutonLifter.h"
#include "AutonPusher.h"
#include "AutonSmartTurn.h"
#include "AutonBincher.h"
#include "AutonIntakeArms.h"
#include "AutonRollers.h"
#include "AutonDelay.h"
#include "AutonWaitForFinished.h"
#include "AutonomousGroupBincher.h"
#include "AutonomousGroupReload.h"

class AutonomousGroup6: public CommandGroup
{
private:
	AutonIntakeArms* m_cAutonArmsOpen1;
	AutonLifter* m_cAutonLifterOut1;
	AutonLifter* m_cAutonLifterStart1; 				//binch
	AutonomousGroupBincher* m_cAutonGroupBincher;

public:
	AutonomousGroup6();
	~AutonomousGroup6();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
