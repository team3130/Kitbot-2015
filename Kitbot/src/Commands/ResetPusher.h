#ifndef RESET_PUSHER_H
#define RESET_PUSHER_H

#include "../CommandBase.h"
#include "WPILib.h"

class ResetPusher: public CommandBase
{
public:
	ResetPusher();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
