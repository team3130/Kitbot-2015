#ifndef AUTONOMOUS_GROUP_6_H
#define AUTONOMOUS_GROUP_6_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "AutonDriveStraight.h"
#include "AutonLifter.h"
#include "AutonPusher.h"
#include "AutonDumbTurn.h"
#include "AutonBincher.h"
#include "AutonIntakeArms.h"

class AutonomousGroup6: public CommandGroup
{
private:
	AutonLifter* m_cAutonLifter1;
	AutonLifter* m_cAutonLifter2;
	AutonLifter* m_cAutonLifter3;
	AutonLifter* m_cAutonLifter4;
	AutonPusher* m_cAutonPusher1;
	AutonDriveStraight* m_cAutonDriveStraight1;
	AutonDumbTurn* m_cAutonTurn1;
	AutonBincher* m_cAutonBincher1;
	AutonBincher* m_cAutonBincher2;
	AutonIntakeArms* m_cAutonArms1;
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
