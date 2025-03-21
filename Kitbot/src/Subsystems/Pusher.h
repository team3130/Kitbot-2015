#ifndef PUSHER_H
#define PUSHER_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Pusher: public Subsystem
{
private:
	CANTalon* m_cPushMotor;
	DigitalOutput* m_cInLED;
	DigitalInput* m_cSwitchIn;
	DigitalInput* m_cSwitchOut;
public:
	Pusher();
	~Pusher();
	void InitDefaultCommand();
	void pushLifter(float speed);
	void SwitchLED(bool status){m_cInLED->Set(status);};
	bool GetLimitSwitchOut(){return (m_cPushMotor->IsRevLimitSwitchClosed() == 1); };
	bool GetLimitSwitchIn(){return (m_cPushMotor->IsFwdLimitSwitchClosed() == 1); };
	int GetDir() {return (m_cPushMotor->Get());};

};

#endif
