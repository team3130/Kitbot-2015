#ifndef CONTROL_ROLLERS_H
#define CONTROL_ROLLERS_H

#include "../CommandBase.h"
#include "WPILib.h"

class ControlRollers: public CommandBase
{
	enum PresetButton {	kIdle, kIn, kOut, kCCW, kCW };
private:
	PresetButton preset;
	double m_nLeftIntake;
	double m_nRightIntake;
public:
	ControlRollers();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
