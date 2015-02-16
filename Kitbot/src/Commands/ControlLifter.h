#ifndef CONTROL_LIFTER_H
#define CONTROL_LIFTER_H

#include "../CommandBase.h"
#include "WPILib.h"

class ControlLifter: public CommandBase
{
	enum PresetButton {	kA, kB, kX, kY };
private:
	bool manualMode;
	bool buttonHold;
	PresetButton preset;
	Timer timer;
public:
	ControlLifter();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
