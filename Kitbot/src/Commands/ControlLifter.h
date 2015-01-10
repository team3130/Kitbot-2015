#ifndef CONTROL_LIFTER_H
#define CONTROL_LIFTER_H

#include "../CommandBase.h"
#include "WPILib.h"

class ControlLifter: public CommandBase
{
public:
	int m_nMoveDirection;
	ControlLifter();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
