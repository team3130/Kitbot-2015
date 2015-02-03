#include "AntlerMoose.h"
#include "../RobotMap.h"
#include "../Commands/ControlAntlerMoose.h"

AntlerMoose::AntlerMoose()
	: Subsystem("AntlerMoose")
{
	m_cAntlerMooseSolenoid = new Solenoid(MOOSELOCK);
	m_bActivated = false;
}

AntlerMoose::~AntlerMoose(){
	delete m_cAntlerMooseSolenoid;
}

void AntlerMoose::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new ControlAntlerMoose());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void AntlerMoose::MoveAntlerLockSolenoid()
{
	m_bActivated = !m_bActivated;
	m_cAntlerMooseSolenoid->Set(m_bActivated);
}
