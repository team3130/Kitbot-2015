#include "AntlerMoose.h"
#include "../RobotMap.h"
#include "../Commands/ControlAntlerMoose.h"

AntlerMoose::AntlerMoose()
	: Subsystem("AntlerMoose")
{
	m_cAntlerLimitSwitchTop = new DigitalInput(ANTLERMOOSESWITCHTOP);
	m_cAntlerLimitSwitchBot = new DigitalInput(ANTLERMOOSESWITCHBOT);
	m_cAntlerMooseLock = new Solenoid(MOOSELOCK);
	m_dLifterPosition = 0;
	m_dEncoderValue=0;
}

AntlerMoose::~AntlerMoose(){
	delete m_cAntlerLimitSwitchTop;
	delete m_cAntlerLimitSwitchBot;
}

void AntlerMoose::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new ControlAntlerMoose());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

// will change orientation if lift winch runs opposite direction
void AntlerMoose::moveAntlerMoose(float speed)
{
	if((speed > 0 and !GetLimitSwitchTop()) or (speed < 0 and !GetLimitSwitchBot())){
		//m_cAntlerMooseMotor->SetSpeed(speed);
	}
}

bool AntlerMoose::GetLimitSwitchTop()
{
	return m_cAntlerLimitSwitchTop->Get();
}

bool AntlerMoose::GetLimitSwitchBot()
{
	return m_cAntlerLimitSwitchBot->Get();
}
