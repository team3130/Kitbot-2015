#ifndef CONTROL_BINCHER_H
#define CONTROL_BINCHER_H

#include "../CommandBase.h"
#include "WPILib.h"

class ControlBincher: public CommandBase
{
private:
	JoystickButton *m_Button;
	bool m_bNewStatus;
public:
	ControlBincher();
	~ControlBincher();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
