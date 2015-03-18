#ifndef AUTONOMOUS_GROUP_8_H
#define AUTONOMOUS_GROUP_8_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "AutonDriveStraight.h"
#include "AutonLifter.h"
#include "AutonPusher.h"
#include "AutonDumbTurn.h"
#include "AutonBincher.h"
#include "AutonIntakeArms.h"
#include "AutonRollers.h"

class AutonomousGroup8: public CommandGroup
{
private:
	AutonLifter* m_cAutonLifter1;
	AutonLifter* m_cAutonLifter2;
	AutonLifter* m_cAutonLifter3;
	AutonLifter* m_cAutonLifter4;
	AutonLifter* m_cAutonLifter5;
	AutonPusher* m_cAutonPusher1;
	AutonDriveStraight* m_cAutonDriveStraight1;
	AutonDriveStraight* m_cAutonDriveStraight2;
	AutonDumbTurn* m_cAutonTurn1;
	AutonBincher* m_cAutonBincher1;
	AutonBincher* m_cAutonBincher2;
	AutonIntakeArms* m_cAutonArms1;
	AutonIntakeArms* m_cAutonArms2;
	AutonRollers* m_cAutonRollers1;
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
