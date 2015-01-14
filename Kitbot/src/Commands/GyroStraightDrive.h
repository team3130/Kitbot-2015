#ifndef GYRO_STRAIGHT_DRIVE_H
#define GYRO_STRAIGHT_DRIVE_H

#include "../CommandBase.h"
#include "WPILib.h"

class GyroStraightDrive: public CommandBase
{
public:
	GyroStraightDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
