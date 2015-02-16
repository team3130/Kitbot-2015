#ifndef AUTONOMOUS_GROUP_2_H
#define AUTONOMOUS_GROUP_2_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "AutonDriveStraight.h"
#include "AutonAntlerMoose.h"
#include "AutonMooseLifter.h"
#include "AutonDumbDrive.h"
#include "AutonTurn.h"

class AutonomousGroup2: public CommandGroup
{
private:
	AutonMooseLifter* m_cMooseLifter1;
	AutonMooseLifter* m_cMooseLifter2;
	AutonAntlerMoose* m_cAntlerMoose1;
	AutonDriveStraight* m_cAutonDrive1;
	AutonDriveStraight* m_cAutonDrive2;
	AutonDriveStraight* m_cAutonDrive3;
	AutonDumbDrive* m_cAutonDumb1;
	AutonTurn* m_cAutonTurner;
public:
	AutonomousGroup2();
	~AutonomousGroup2();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
