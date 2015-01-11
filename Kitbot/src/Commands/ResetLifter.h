#ifndef RESET_LIFTER_H
#define RESET_LIFTER_H

#include "../CommandBase.h"
#include "WPILib.h"

class ResetLifter: public CommandBase
{
public:
	ResetLifter();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
