#ifndef AUTONOMOUS_GROUP5_H
#define AUTONOMOUS_GROUP5_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "AutonDriveStraight.h"
#include "AutonLifter.h"
#include "AutonTurn.h"

class AutonomousGroup5: public CommandGroup
{
private:

public:
	AutonomousGroup5();
	~AutonomousGroup5();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
