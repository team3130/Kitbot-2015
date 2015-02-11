#include "Pusher.h"
#include "../RobotMap.h"
#include "../Commands/ControlPusher.h"

Pusher::Pusher()
	: Subsystem("Pusher")
{
	m_cPushMotor = new CANTalon(PUSHER);
	m_cPushMotor->ConfigLimitMode(CANTalon::kLimitMode_SwitchInputsOnly);
	m_cPushMotor->ConfigNeutralMode(CANTalon::kNeutralMode_Brake);
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
	m_cPushMotor->SetControlMode(CANSpeedController::kPercentVbus);
	m_cPushMotor->Set(speed);
}
