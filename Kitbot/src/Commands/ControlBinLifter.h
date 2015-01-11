#ifndef CONTROLBINLIFTER_H
#define CONTROLBINLIFTER_H

#include "../CommandBase.h"
#include "WPILib.h"

class ControlBinLifter: public CommandBase
{
public:
	ControlBinLifter();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
