#ifndef AUTONOMOUS_GROUP_Reload_H
#define AUTONOMOUS_GROUP_Reload_H

#include "WPILib.h"
#include "AutonLifter.h"
#include "AutonDelay.h"

class AutonomousGroupReload: public CommandGroup
{
private:
	AutonLifter* m_cAutonLifterDown;
	AutonLifter* m_cAutonLifterUp;
	AutonDelay* m_cAutonDelayBottom;
public:
	AutonomousGroupReload();
	~AutonomousGroupReload();
	void Initialize();
	void SetGoal(double endingHeight);
	void Execute();
	void End();
	void Interrupted();
};

#endif
