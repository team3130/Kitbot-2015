#ifndef AUTON_LIFTER_H
#define AUTON_LIFTER_H

#include "../CommandBase.h"
#include "WPILib.h"

class AutonLifter: public CommandBase
{
public:
	enum PushDirection { kNone, kIn, kOut };
private:
	Timer* timer;
	double m_waitTime;
	double m_dThreshold;
	double m_dEncoderGoal;
	PushDirection m_Push;
	bool m_bPusherDone;
public:
	AutonLifter();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	void SetGoal(double timeout, double thresh, double goal, PushDirection push=kNone){
		m_waitTime = timeout;
		m_dThreshold = thresh;
		m_dEncoderGoal = goal;
		m_Push = push;
	};
};

#endif
