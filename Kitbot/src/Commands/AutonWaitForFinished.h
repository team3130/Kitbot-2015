#ifndef AUTON_WAITFORFINISHED_H
#define AUTON_WAITFORFINISHED_H

#include "WPILib.h"
#include <sstream>

class AutonWaitForFinished: public Command
{
private:
	Command* m_Slacker;
public:
	AutonWaitForFinished();
	AutonWaitForFinished(double timeout);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	void SetGoal(Command *pTargetCommand) { m_Slacker = pTargetCommand; };
};

#endif
