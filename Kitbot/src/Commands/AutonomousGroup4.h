#ifndef AUTONOMOUS_GROUP_4_H
#define AUTONOMOUS_GROUP_4_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "AutonDriveStraight.h"
#include "AutonAntlerMoose.h"
#include "AutonMooseLifter.h"
#include "AutonDumbDrive.h"
#include "AutonTurn.h"
#include "AutonIntakeArms.h"

class AutonomousGroup4: public CommandGroup
{
private:
	AutonMooseLifter* m_cMooseLifter1;
	AutonDriveStraight* m_cAutonDrive1;
	AutonDriveStraight* m_cAutonDrive2;
	AutonDumbDrive* m_cAutonDumb1;
public:
	AutonomousGroup4();
	~AutonomousGroup4();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
