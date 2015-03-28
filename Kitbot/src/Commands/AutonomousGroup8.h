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
	AutonLifter* m_cAutonLifter3; 				//binch
	AutonLifter* m_cAutonLifter4;
	AutonLifter* m_cAutonLifter5;
	AutonLifter* m_cAutonLifter6;
	AutonLifter* m_cAutonLifter7;
	AutonLifter* m_cAutonLifter8;
	AutonLifter* m_cAutonLifter9;
	AutonPusher* m_cAutonPusher1; 				// binch
	AutonDriveStraight* m_cAutonDriveStraight0;
	AutonDriveStraight* m_cAutonDriveStraight1;
	AutonDriveStraight* m_cAutonDriveStraight2;
	AutonDriveStraight* m_cAutonDriveStraight3;
	AutonDriveStraight* m_cAutonDriveStraight4;
	AutonDriveStraight* m_cAutonDriveStraight5;
	AutonDriveStraight* m_cAutonDriveStraight6;
	AutonDriveStraight* m_cAutonDriveStraight7;
	AutonDriveStraight* m_cAutonDriveStraight8;
	AutonDriveStraight* m_cAutonDriveStraight9;
	AutonSmartTurn* m_cAutonDriveTurn2;
	AutonDriveStraight* m_cAutonDriveIntake2;
	AutonDriveStraight* m_cAutonDriveAfterTurn2;
	AutonSmartTurn* m_cAutonDriveTurn3;
	AutonDriveStraight* m_cAutonDriveIntake3;
	AutonDriveStraight* m_cAutonDriveAfterTurn3;
	AutonSmartTurn* m_cAutonTurn1;
	AutonSmartTurn* m_cAutonTurn2;
	AutonBincher* m_cAutonBincher1;				//binch
	AutonBincher* m_cAutonBincher2;				//binch
	AutonIntakeArms* m_cAutonArms1;				//binch
	AutonIntakeArms* m_cAutonArms2;
	AutonIntakeArms* m_cAutonArms3;
	AutonIntakeArms* m_cAutonArms4;
	AutonIntakeArms* m_cAutonArms5;
	AutonIntakeArms* m_cAutonArms6;
	AutonRollers* m_cAutonRollers1;
	AutonRollers* m_cAutonRollers2;
	AutonDelay* m_cAutonDelay1;
	AutonDelay* m_cAutonDelay2;
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
