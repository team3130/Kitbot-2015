#ifndef ACCELEROMETER_TEST_H
#define ACCELEROMETER_TEST_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "valarray"

class AccelerometerTest: public CommandBase
{
private:
	double dT;
	std::valarray<double> a;
	std::valarray<double> g;
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
