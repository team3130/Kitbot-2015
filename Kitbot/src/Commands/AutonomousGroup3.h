#ifndef AUTONOMOUS_GROUP_3_H
#define AUTONOMOUS_GROUP_3_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "AutonDriveStraight.h"
#include "AutonSmartTurn.h"

class AutonomousGroup3: public CommandGroup
{
private:
	AutonDriveStraight* m_cAutonDumbDrive1;
	AutonSmartTurn* m_cTurn1;
public:
	AutonomousGroup3();
	~AutonomousGroup3();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
