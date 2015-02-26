#ifndef AUTONOMOUS_GROUP_3_H
#define AUTONOMOUS_GROUP_3_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "AutonDumbDrive.h"

class AutonomousGroup3: public CommandGroup
{
private:
	AutonDumbDrive* m_cAutonDumbDrive1;
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
