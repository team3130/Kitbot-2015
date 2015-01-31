#ifndef AUTONOMOUS_GROUP_2_H
#define AUTONOMOUS_GROUP_2_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "AutonDriveStraight.h"
#include "AutonAntlerMoose.h"
#include "AutonMooseLifter.h"

class AutonomousGroup: public CommandGroup
{
private:
	AutonMooseLifter* m_cMooseLifter1;
	AutonMooseLifter* m_cMooseLifter2;
	AutonAntlerMoose* m_cAntlerMoose1;
	AutonDriveStraight* m_cAutonDrive1;
	AutonDriveStraight* m_cAutonDrive2;
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
