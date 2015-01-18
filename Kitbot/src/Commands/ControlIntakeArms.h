#ifndef CONTROL_INTAKE_ARMS_H
#define CONTROL_INTAKE_ARMS_H

#include "../CommandBase.h"
#include "WPILib.h"

class ControlIntakeArms: public CommandBase
{
public:
	bool m_bArmsExtended;
	ControlIntakeArms();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
