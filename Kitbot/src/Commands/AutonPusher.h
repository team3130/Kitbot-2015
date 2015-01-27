#ifndef AUTON_PUSHER_H
#define AUTON_PUSHER_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutonPusher: public CommandBase
{
public:
	bool m_bPusherExecute;
	bool m_fDirection;
	AutonPusher();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
