#ifndef AUTONOMOUS_GROUP_Reload_H
#define AUTONOMOUS_GROUP_Reload_H

#include "WPILib.h"
#include "AutonLifter.h"

class AutonomousGroupReload: public CommandGroup
{
private:
	AutonLifter* m_cAutonLifterDown;
	AutonLifter* m_cAutonLifterUp;
public:
	AutonomousGroupReload();
	~AutonomousGroupReload();
	void Initialize();
	void SetGoal(double endingHeight);
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
