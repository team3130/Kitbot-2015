#ifndef CONTROL_PUSHER_H
#define CONTROL_PUSHER_H

#include "../CommandBase.h"
#include "WPILib.h"

class ControlPusher: public CommandBase
{
public:
	ControlPusher();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
