#ifndef PUSHER_H
#define PUSHER_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Pusher: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	CANTalon* m_cPushMotor;
public:
	Pusher();
	~Pusher();
	void InitDefaultCommand();
	void pushLifter(float speed);
	bool GetLimitSwitchOut();
	bool GetLimitSwitchIn();

};

#endif
