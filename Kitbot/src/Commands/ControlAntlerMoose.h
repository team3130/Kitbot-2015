#ifndef CONTROL_ANTLER_MOOSE_H
#define CONTROL_ANTLER_MOOSE_H

#include "../CommandBase.h"
#include "WPILib.h"

class ControlAntlerMoose: public CommandBase
{
private:
	JoystickButton *m_Button;
	JoystickButton *m_ButtonLeft;
	JoystickButton *m_ButtonRight;
public:
	ControlAntlerMoose();
	~ControlAntlerMoose();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
