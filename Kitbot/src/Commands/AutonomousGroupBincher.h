#ifndef AUTONOMOUS_GROUP_BINCHER_H
#define AUTONOMOUS_GROUP_BINCHER_H

#include "WPILib.h"
#include "AutonLifter.h"
#include "AutonBincher.h"
#include "AutonWaitForFinished.h"

class AutonomousGroupBincher: public CommandGroup
{
private:
	AutonLifter* m_cAutonLifterDown;
	AutonLifter* m_cAutonLifterUp;
	AutonLifter* m_cAutonLifterLower;
	AutonBincher* m_cAutonBincherOpen;
	AutonBincher* m_cAutonBincherClamp;
public:
	AutonomousGroupBincher();
	~AutonomousGroupBincher();
	void Initialize();
	void SetGoal(double top, double end);
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
