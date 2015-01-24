#ifndef ACCELEROMETER_TEST_H
#define ACCELEROMETER_TEST_H

#include "../CommandBase.h"
#include "WPILib.h"

class AccelerometerTest: public CommandBase
{
private:
	double dT;
	double x;
	double y;
	double xSpeed;
	double ySpeed;
	double xAcceleration;
	double yAcceleration;
	Accelerometer* accelerometer;
	Timer* timer;
public:
	AccelerometerTest();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
