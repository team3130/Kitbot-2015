#ifndef GYRO_TEST_H
#define GYRO_TEST_H

#include "../CommandBase.h"
#include "WPILib.h"

class GyroTest: public CommandBase
{
private:
	const float m_dKp = 0.3; //arbitrary constant to correct turning
	Timer timer;
	double goalTime;
	float moveSpeed;
	float angle;
public:
	GyroTest();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
