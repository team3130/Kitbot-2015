#ifndef CONTROL_LIFTER_H
#define CONTROL_LIFTER_H

#include "../CommandBase.h"
#include "WPILib.h"

class ControlLifter: public CommandBase
{
private:
	bool manualMode;
	int goal;
public:
	ControlLifter();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
