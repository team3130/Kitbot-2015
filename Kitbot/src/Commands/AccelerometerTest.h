#ifndef ACCELEROMETER_TEST_H
#define ACCELEROMETER_TEST_H

#include "../CommandBase.h"
#include "WPILib.h"

class AccelerometerTest: public CommandBase
{
private:
	double dT;
	double x,y,z;
	double x0,y0,z0;
	double xSpeed,ySpeed,zSpeed;
	double xAcceleration,yAcceleration,zAcceleration;
	BuiltInAccelerometer* accelerometer;
	Timer* timer;
public:
	const double GRAVITY_ACC = 9.81;
	AccelerometerTest();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
