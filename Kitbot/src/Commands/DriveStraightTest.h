#ifndef DRIVE_STRAIGHT_TEST_H
#define DRIVE_STRAIGHT_TEST_H

#include "../CommandBase.h"
#include "WPILib.h"

class DriveStraightTest: public CommandBase
{
public:
	DriveStraightTest();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
