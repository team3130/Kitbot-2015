#ifndef AUTONOMOUS_GROUP_H
#define AUTONOMOUS_GROUP_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "AutonDriveStraight.h"
#include "AutonLifter.h"
#include "AutonRollers.h"
#include "AutonPusher.h"

class AutonomousGroup: public CommandGroup
{
private:
	AutonLifter* m_cAutonLifter1;
	AutonLifter* m_cAutonLifter2;
	AutonLifter* m_cAutonLifter3;
	AutonLifter* m_cAutonLifter4;
	AutonRollers* m_cAutonRollers1;
	AutonRollers* m_cAutonRollers2;
	AutonRollers* m_cAutonRollers3;
	AutonRollers* m_cAutonRollers4;
	AutonPusher* m_cAutonOutput;
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
