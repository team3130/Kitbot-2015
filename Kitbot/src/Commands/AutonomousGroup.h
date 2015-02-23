#ifndef AUTONOMOUS_GROUP_H
#define AUTONOMOUS_GROUP_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "AutonDriveStraight.h"
#include "AutonLifter.h"
#include "AutonPusher.h"
#include "AutonRollers.h"
#include "AutonTurn.h"

class AutonomousGroup: public CommandGroup
{
private:
	AutonLifter* m_cAutonLifter1;
	AutonLifter* m_cAutonLifter2;
	AutonLifter* m_cAutonLifter3;
	AutonPusher* m_cAutonPusher1;
	AutonPusher* m_cAutonPusher2;
	AutonRollers* m_cAutonRollers1;
	AutonDriveStraight* m_cAutonDriveStraight1;
	AutonDriveStraight* m_cAutonDriveStraight2;
	AutonTurn* m_cAutonTurn1;
public:
	AutonomousGroup();
	~AutonomousGroup();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
