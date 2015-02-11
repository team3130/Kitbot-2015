#ifndef ROBOT_SENSORS_H
#define ROBOT_SENSORS_H

#include "../CommandBase.h"

class RobotSensors: public CommandBase
{
private:
	AnalogInput* range;
public:
	RobotSensors();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

