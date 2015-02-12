#ifndef CONTROL_MOOSE_LIFTER_H
#define CONTROL_MOOSE_LIFTER_H

#include "../CommandBase.h"
#include "WPILib.h"

class ControlMooseLifter: public CommandBase
{
public:
	ControlMooseLifter();
	~ControlMooseLifter();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool m_bWatchLoop;
	bool m_bNewStatus;
	JoystickButton *m_Button;
};

#endif
