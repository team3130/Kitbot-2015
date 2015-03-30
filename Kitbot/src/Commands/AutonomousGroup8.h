#ifndef AUTONOMOUS_GROUP_8_H
#define AUTONOMOUS_GROUP_8_H

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

class AutonomousGroup8: public CommandGroup
{
private:
	AutonomousGroupBincher* m_cAutonGroupBincher;

	AutonLifter* m_cAutonLifterStart1; 				//binch
	AutonLifter* m_cAutonLifterGrab1; 				//binch
	AutonSmartTurn* m_cAutonTurn1;
	AutonDriveStraight* m_cAutonApproach1;
	AutonDriveStraight* m_cAutonDriveIntake1;
	AutonIntakeArms* m_cAutonArmsOpen1;
	AutonIntakeArms* m_cAutonArmsClose1;
	AutonRollers* m_cAutonRollers1;
	AutonWaitForFinished* m_cAutonWaitForBin;
	AutonWaitForFinished* m_cAutonWaitForBincher;

	AutonSmartTurn* m_cAutonTurn2;
	AutonDriveStraight* m_cAutonApproach2;
	AutonDriveStraight* m_cAutonDriveIntake2;
	AutonIntakeArms* m_cAutonArmsOpen2;
	AutonIntakeArms* m_cAutonArmsClose2;
	AutonRollers* m_cAutonRollersOut2;
	AutonRollers* m_cAutonRollersIn2;
	AutonomousGroupReload* m_cAutonReload2;
	AutonWaitForFinished* m_cAutonWaitForReload2;

	AutonSmartTurn* m_cAutonTurn3;
	AutonDriveStraight* m_cAutonApproach3;
	AutonDriveStraight* m_cAutonDriveIntake3;
	AutonIntakeArms* m_cAutonArmsOpen3;
	AutonIntakeArms* m_cAutonArmsClose3;
	AutonRollers* m_cAutonRollersOut3;
	AutonRollers* m_cAutonRollersIn3;
	AutonomousGroupReload* m_cAutonReload3;
	AutonWaitForFinished* m_cAutonWaitForReload3;

	AutonDriveStraight* m_cAutonDriveAutozone;
	AutonLifter* m_cAutonLifterDrop;
	AutonRollers* m_cAutonRollersEject;
	AutonDriveStraight* m_cAutonDriveBackout;

public:
	AutonomousGroup8();
	~AutonomousGroup8();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
