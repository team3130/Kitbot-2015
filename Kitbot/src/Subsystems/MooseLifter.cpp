#include "MooseLifter.h"
#include "../RobotMap.h"
#include "../Commands/ControlMooseLifter.h"

MooseLifter::MooseLifter()
	: Subsystem("MooseLifter")
{
	m_cMooseLiftMotor = new Jaguar(MOOSELIFTER);
	m_cMooseSolenoid = new Solenoid(COMPRESSOR, MOOSELIFTER);
	m_cMooseLock = new Solenoid(COMPRESSOR, MOOSELOCK);
	m_cMooseLimitSwitchTop = new DigitalInput(MOOSELIFTERSWITCHTOP);
	m_cMooseLimitSwitchBot = new DigitalInput(MOOSELIFTERSWITCHBOT);
}

MooseLifter::~MooseLifter(){
	delete m_cMooseLimitSwitchTop;
	delete m_cMooseLimitSwitchBot;
	delete m_cMooseLiftMotor;
	delete m_cMooseSolenoid;
	delete m_cMooseLock;
}

void MooseLifter::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new ControlMooseLifter());
}

void MooseLifter::MoveMooseLifterSolenoid(bool direction)
{
	m_cMooseSolenoid->Set(direction);
}

void MooseLifter::MoveMooseLock(bool activated)
{
	m_cMooseLock->Set(activated);
}

// will change orientation if lift winch runs opposite direction
void MooseLifter::MoveMooseLifterMotor(float speed)
{
	if((speed > 0 and !GetLimitSwitchTop()) or (speed < 0 and !GetLimitSwitchBot())){
		m_cMooseLiftMotor->SetSpeed(speed);
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
