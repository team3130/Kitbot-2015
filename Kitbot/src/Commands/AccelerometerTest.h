#ifndef ACCELEROMETER_TEST_H
#define ACCELEROMETER_TEST_H

#include "../CommandBase.h"
#include "WPILib.h"

class AccelerometerTest: public CommandBase
{
private:
	double xSpeed;
	double ySpeed;

public:
	AccelerometerTest();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
