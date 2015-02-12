#include "AntlerMoose.h"
#include "../RobotMap.h"
#include "../Commands/ControlAntlerMoose.h"

AntlerMoose::AntlerMoose()
	: Subsystem("AntlerMoose")
{
	m_cAntlerMooseLock = new Solenoid(COMPRESSOR, MOOSELOCK);
	m_bActivated = false;
}

AntlerMoose::~AntlerMoose(){
	delete m_cAntlerMooseLock;
}

void AntlerMoose::InitDefaultCommand()
{
	SetDefaultCommand(new ControlAntlerMoose());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void AntlerMoose::MoveAntlerLock(bool activate)
{
	m_bActivated = activate;
	m_cAntlerMooseLock->Set(m_bActivated);
}
