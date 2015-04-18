#ifndef AUTONOMOUS_GROUP_7_H
#define AUTONOMOUS_GROUP_7_H

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

class AutonomousGroup7: public CommandGroup
{
private:
	AutonLifter* lft_AutonUp1;
	AutonLifter* lft_AutonUp2;
	AutonLifter* lft_AutonUp3;
	AutonLifter* lft_AutonDown1;
	AutonLifter* lft_AutonDown2;
	AutonLifter* lft_AutonDown3;
	AutonDriveStraight* drv_AutonToBin1;
	AutonDriveStraight* drv_AutonToBin2;
	AutonDriveStraight* drv_AutonToteIn1;
	AutonDriveStraight* drv_AutonToteIn2;
	AutonDriveStraight* drv_AutonZone1;
	AutonDriveStraight* drv_AutonZone2;
	AutonDriveStraight* drv_AutonBack1;
	AutonDriveStraight* drv_AutonBack2;
	AutonSmartTurn* trn_AutonKnockBin1;
	AutonSmartTurn* trn_AutonKnockBin2;
	AutonSmartTurn* trn_AutonZoneTurn1;
	AutonRollers* whl_AutonIntakeIn1;
	AutonRollers* whl_AutonIntakeIn2;
	AutonRollers* whl_AutonIntakeOut1;


public:
	AutonomousGroup7();
	~AutonomousGroup7();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
