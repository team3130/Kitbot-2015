#ifndef PUSHER_H
#define PUSHER_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Pusher: public Subsystem
{
private:
	CANTalon* m_cPushMotor;
public:
	Pusher();
	~Pusher();
	void InitDefaultCommand();
	void pushLifter(float speed);
	bool GetLimitSwitchOut(){return m_cPushMotor->GetForwardLimitOK();};
	bool GetLimitSwitchIn(){return m_cPushMotor->GetReverseLimitOK();};

};

#endif
