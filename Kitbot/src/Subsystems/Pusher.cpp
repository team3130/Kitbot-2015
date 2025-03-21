#include "Pusher.h"
#include "../RobotMap.h"
#include "../Commands/ControlPusher.h"

Pusher::Pusher()
	: Subsystem("Pusher")
{
	m_cPushMotor = new CANTalon(PUSHER);
	m_cPushMotor->ConfigNeutralMode(CANTalon::kNeutralMode_Brake);
	m_cPushMotor->SetControlMode(CANSpeedController::kPercentVbus);
	m_cPushMotor->ConfigLimitMode(CANTalon::kLimitMode_SrxDisableSwitchInputs);
	m_cInLED = new DigitalOutput(PUSHER_LED);
	m_cSwitchIn = new DigitalInput(PUSHER_LIMIT_IN);
	m_cSwitchOut = new DigitalInput(PUSHER_LIMIT_OUT);
}

Pusher::~Pusher(){
	delete m_cPushMotor;
	delete m_cSwitchIn;
	delete m_cSwitchOut;
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
	//m_cPushMotor->Set(speed);
	if((speed < 0 and !GetLimitSwitchOut()) or (speed > 0 and !GetLimitSwitchIn()) or speed == 0){
		m_cPushMotor->Set(speed);
	}
	else {
		m_cPushMotor->Set(0);
	}
}
