#ifndef AUTONOMOUS_GROUP_7_H
#define AUTONOMOUS_GROUP_7_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "AutonDriveStraight.h"
#include "AutonLifter.h"
#include "AutonPusher.h"
#include "AutonDumbTurn.h"
#include "AutonBincher.h"
#include "AutonIntakeArms.h"
#include "AutonRollers.h"

class AutonomousGroup7: public CommandGroup
{
private:
	AutonLifter* m_cAutonLifter1;
	AutonLifter* m_cAutonLifter2;
	AutonLifter* m_cAutonLifter3;
	AutonLifter* m_cAutonLifter4;
	AutonLifter* m_cAutonLifter5;
	AutonLifter* m_cAutonLifter6;
	AutonLifter* m_cAutonLifter7;
	AutonLifter* m_cAutonLifter8;
	AutonLifter* m_cAutonLifter9;
	AutonPusher* m_cAutonPusher1;
	AutonDriveStraight* m_cAutonDriveStraight1;
	AutonDriveStraight* m_cAutonDriveStraight2;
	AutonDriveStraight* m_cAutonDriveStraight3;
	AutonDriveStraight* m_cAutonDriveStraight4;
	AutonDumbTurn* m_cAutonTurn1;
	AutonBincher* m_cAutonBincher1;
	AutonBincher* m_cAutonBincher2;
	AutonIntakeArms* m_cAutonArms1;
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
