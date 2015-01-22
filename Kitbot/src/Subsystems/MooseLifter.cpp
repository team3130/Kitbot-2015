#include "MooseLifter.h"
#include "../RobotMap.h"
#include "../Commands/ControlMooseLifter.h"

MooseLifter::MooseLifter()
	: Subsystem("MooseLifter")
{
	m_cMooseLiftMotor = new Jaguar(MOOSELIFTER);
	m_cMooseSolenoid = new Solenoid(MOOSELIFTER);
	m_cMooseLimitSwitchTop = new DigitalInput(MOOSELIFTERSWITCHTOP);
	m_cMooseLimitSwitchBot = new DigitalInput(MOOSELIFTERSWITCHBOT);
	m_dMooseLifterPosition = 0;
	m_dEncoderValue=0;
}

MooseLifter::~MooseLifter(){
	delete m_cMooseLimitSwitchTop;
	delete m_cMooseLimitSwitchBot;
	delete m_cMooseLiftMotor;
	delete m_cMooseSolenoid;
}

void MooseLifter::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new ControlMooseLifter());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

// will change orientation if lift winch runs opposite direction
void MooseLifter::MoveMooseLifterMotor(float speed)
{
	if((speed > 0 and !GetLimitSwitchTop()) or (speed < 0 and !GetLimitSwitchBot())){
		m_cMooseLiftMotor->SetSpeed(speed);
	}
}

void MooseLifter::MoveMooseLifterSolonoid(float direction)
{
	if((direction > 0 and !GetLimitSwitchTop()) or (direction < 0 and !GetLimitSwitchBot())){
		if(direction > 0){m_cMooseSolenoid->Set(1);}
		else if(direction < 0){m_cMooseSolenoid->Set(0);}
	}
}

bool MooseLifter::GetLimitSwitchTop()
{
	return m_cMooseLimitSwitchTop->Get();
	SmartDashboard::PutBoolean("Moose-Top Limit Switch", m_cMooseLimitSwitchTop->Get());
}

bool MooseLifter::GetLimitSwitchBot()
{
	return m_cMooseLimitSwitchBot->Get();
	SmartDashboard::PutBoolean("Moose-Top Limit Switch", m_cMooseLimitSwitchBot->Get());

}
