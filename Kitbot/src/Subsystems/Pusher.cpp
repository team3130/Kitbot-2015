#include "Pusher.h"
#include "../RobotMap.h"
#include "../Commands/ControlPusher.h"

Pusher::Pusher()
	: Subsystem("Pusher")
{
	m_cPushMotor = new CANTalon(PUSHER);
	m_cPushMotor->SetControlMode(CANSpeedController::kPercentVbus);
}

Pusher::~Pusher(){
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
	m_cPushMotor->Set(speed);
}

bool Pusher::GetLimitSwitchOut()
{
	SmartDashboard::PutBoolean("Pusher-Out Limit Switch", m_cPushMotor->GetForwardLimitOK());
	return m_cPushMotor->GetForwardLimitOK();
}

bool Pusher::GetLimitSwitchIn()
{
	SmartDashboard::PutBoolean("Pusher-In Limit Switch", m_cPushMotor->GetReverseLimitOK());
	return m_cPushMotor->GetReverseLimitOK();
}
