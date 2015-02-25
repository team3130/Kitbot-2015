#ifndef AUTONOMOUS_GROUP_H
#define AUTONOMOUS_GROUP_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "AutonDriveStraight.h"
#include "AutonLifter.h"
#include "AutonTurn.h"

class AutonomousGroup: public CommandGroup
{
private:
	AutonLifter* m_cAutonLifter1;
	AutonDriveStraight* m_cAutonDriveStraight1;
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
