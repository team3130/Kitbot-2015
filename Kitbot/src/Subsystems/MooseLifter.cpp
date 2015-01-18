#include "MooseLifter.h"
#include "../RobotMap.h"
#include "../Commands/ControlMooseLifter.h"

MooseLifter::MooseLifter()
	: Subsystem("MooseLifter")
{
	m_cMooseLiftMotor = new Talon(MOOSELIFTER);
	m_cMooseSolonoid = new Solenoid(MOOSELIFTER);
	m_cLimitSwitchTop = new DigitalInput(MOOSELIFTERSWITCHTOP);
	m_cLimitSwitchBot = new DigitalInput(MOOSELIFTERSWITCHBOT);
	m_dLifterPosition = 0;
	m_dEncoderValue=0;
}

MooseLifter::~MooseLifter(){
	delete m_cLimitSwitchTop;
	delete m_cLimitSwitchBot;
	delete m_cMooseLiftMotor;
}

void MooseLifter::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new ControlMooseLifter());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

// will change orientation if lift winch runs opposite direction
void MooseLifter::moveMooseLifter(float speed)
{
	if((speed > 0 and !GetLimitSwitchTop()) or (speed < 0 and !GetLimitSwitchBot())){
		m_cMooseLiftMotor->SetSpeed(speed);
	}
}

bool MooseLifter::GetLimitSwitchTop()
{
	return m_cLimitSwitchTop->Get();
}

bool MooseLifter::GetLimitSwitchBot()
{
	return m_cLimitSwitchBot->Get();
}
