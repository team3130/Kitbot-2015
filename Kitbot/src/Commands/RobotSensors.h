#ifndef ROBOT_SENSORS_H
#define ROBOT_SENSORS_H

#include "../CommandBase.h"

class RobotSensors: public CommandBase
{
private:
	static bool lifterZero;
	SerialPort* arduino;
	Timer* timer;
public:
	RobotSensors();
	~RobotSensors();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	static void LifterReset() { lifterZero = true; };
};

#endif

