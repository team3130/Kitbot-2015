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
	DigitalInput* m_cLimitSwitchIn;
	DigitalInput* m_cLimitSwitchOut;
public:
	Pusher();
	~Pusher();
	void InitDefaultCommand();
	void pushLifter(float speed);
	bool GetLimitSwitchIn();
	bool GetLimitSwitchOut();

};

#endif
