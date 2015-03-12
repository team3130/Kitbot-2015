#ifndef AUTONOMOUS_GROUP_4_H
#define AUTONOMOUS_GROUP_4_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "AutonDriveStraight.h"
#include "AutonLifter.h"
#include "AutonPusher.h"
#include "AutonTurn.h"
#include "AutonBincher.h"

class AutonomousGroup4: public CommandGroup
{
private:
	AutonLifter* m_cAutonLifter1;
	AutonPusher* m_cAutonPusher1;
	AutonPusher* m_cAutonPusher2;
	AutonDriveStraight* m_cAutonDriveStraight1;
	AutonTurn* m_cAutonTurn1;
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
