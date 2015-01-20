#ifndef AUTONOMOUS_GROUP_H
#define AUTONOMOUS_GROUP_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "ControlLifter.h"
#include "ControlRollers.h"

class AutonomousGroup: public CommandBase
{
private:
	ControlLifter* m_cAutonLifter;
	ControlRollers* m_cAutonRollers;


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
