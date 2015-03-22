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
	AutonDriveStraight* m_cAutonDriveStraight1;
	AutonDriveStraight* m_cAutonDriveStraight2;
	AutonDriveStraight* m_cAutonDriveStraight3;
	AutonDriveStraight* m_cAutonDriveStraight4;
	AutonDriveStraight* m_cAutonDriveStraight5;
	AutonDriveStraight* m_cAutonDriveStraight6;
	AutonDriveStraight* m_cAutonDriveStraight7;
	AutonDriveStraight* m_cAutonDriveStraight8;
	AutonDriveStraight* m_cAutonDriveStraight9;
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
	AutonRollers* m_cAutonRollers3;
	AutonRollers* m_cAutonRollers4;
	AutonRollers* m_cAutonRollers5;
	AutonRollers* m_cAutonRollers6;
	AutonDelay* m_cAutonDelay1;
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
