#ifndef AUTON_BINCHER_H
#define AUTON_BINCHER_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutonBincher: public CommandBase
{
private:
	bool m_bDirection;
	bool m_bRan;
public:
	AutonBincher();
	~AutonBincher();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	void SetDir(bool bDirection){m_bDirection = bDirection;}
};

#endif
