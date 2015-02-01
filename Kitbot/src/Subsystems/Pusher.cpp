#include "Pusher.h"
#include "../RobotMap.h"
#include "../Commands/ControlPusher.h"

Pusher::Pusher()
	: Subsystem("Pusher")
{
	m_cPushMotor = new CANTalon(PUSHER);
	m_cLimitSwitchIn = new DigitalInput(LIFTERSWITCHIN);
	m_cLimitSwitchOut = new DigitalInput(LIFTERSWITCHOUT);
	m_cPushMotor->SetControlMode(m_cPushMotor->kPercentVbus);
}

Pusher::~Pusher(){
	delete m_cLimitSwitchIn;
	delete m_cLimitSwitchOut;
	delete m_cPushMotor;
}

void Pusher::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new ControlPusher());
}

//will change orientation if pusher screw runs opposite direction
void Pusher::pushLifter(float speed)
{
	if((speed > 0 and !GetLimitSwitchOut()) or (speed < 0 and !GetLimitSwitchIn())){
		m_cPushMotor->Set(speed);
	}
}

bool Pusher::GetLimitSwitchIn()
{
	return m_cLimitSwitchIn->Get();
	SmartDashboard::PutBoolean("Lifter-Inner Limit Switch", m_cLimitSwitchIn->Get());
}

bool Pusher::GetLimitSwitchOut()
{
	return m_cLimitSwitchOut->Get();
	SmartDashboard::PutBoolean("Lifter-Outer Limit Switch", m_cLimitSwitchOut->Get());
}
