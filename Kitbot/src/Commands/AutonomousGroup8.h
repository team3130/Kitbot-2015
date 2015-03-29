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

class AutonomousGroup8: public CommandGroup
{
private:
	AutonLifter* m_cAutonLifter1; 				//binch
	AutonLifter* m_cAutonLifter2; 				//binch
	AutonLifter* m_cAutonLifterAssure; 				//binch
	AutonLifter* m_cAutonLifterUnbinch; 				//binch
	AutonLifter* m_cAutonLifter4;
	AutonLifter* m_cAutonLifter5;
	AutonLifter* m_cAutonLifterDown2;
	AutonLifter* m_cAutonLifterUp2;
	AutonLifter* m_cAutonLifterDown3;
	AutonLifter* m_cAutonLifterUp3;
	AutonLifter* m_cAutonLifterDrop;
	AutonDriveStraight* m_cAutonDriveStraight0;
	AutonDriveStraight* m_cAutonDriveStraight1;
	AutonDriveStraight* m_cAutonDriveStraight2;
	AutonDriveStraight* m_cAutonApproach2;
	AutonDriveStraight* m_cAutonDriveAutozone;
	AutonDriveStraight* m_cAutonDriveStraight5;
	AutonDriveStraight* m_cAutonDriveStraight6;
	AutonDriveStraight* m_cAutonDriveBackout;
	AutonDriveStraight* m_cAutonDriveStraight8;
	AutonDriveStraight* m_cAutonDriveStraight9;
	AutonSmartTurn* m_cAutonDriveTurn2;
	AutonDriveStraight* m_cAutonDriveIntake2;
	AutonDriveStraight* m_cAutonApproach3;
	AutonSmartTurn* m_cAutonDriveTurn3;
	AutonDriveStraight* m_cAutonDriveIntake3;
	AutonDriveStraight* m_cAutonDriveAfterTurn3;
	AutonSmartTurn* m_cAutonTurn1;
	AutonSmartTurn* m_cAutonTurn2;
	AutonSmartTurn* m_cAutonTurn3;
	AutonBincher* m_cAutonBincher1;				//binch
	AutonBincher* m_cAutonBincher2;				//binch
	AutonIntakeArms* m_cAutonArms1;				//binch
	AutonIntakeArms* m_cAutonArms2;
	AutonIntakeArms* m_cAutonArmsOpen2;
	AutonIntakeArms* m_cAutonArmsClose2;
	AutonIntakeArms* m_cAutonArmsOpen3;
	AutonIntakeArms* m_cAutonArmsClose3;
	AutonRollers* m_cAutonRollers1;
	AutonRollers* m_cAutonRollersEject;
	AutonRollers* m_cAutonRollersOut2;
	AutonRollers* m_cAutonRollersIn2;
	AutonRollers* m_cAutonRollersOut3;
	AutonRollers* m_cAutonRollersIn3;
	AutonDelay* m_cAutonDelayBottom;
	AutonDelay* m_cAutonDelaySuck;
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
