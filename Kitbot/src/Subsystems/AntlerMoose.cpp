#include "AntlerMoose.h"
#include "../RobotMap.h"
#include "../Commands/ControlAntlerMoose.h"

AntlerMoose::AntlerMoose()
	: Subsystem("AntlerMoose")
{
	m_cAntlerMooseLock = new Solenoid(MOOSELOCK);
}

AntlerMoose::~AntlerMoose(){
	delete m_cAntlerMooseLock;
}

void AntlerMoose::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new ControlAntlerMoose());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void AntlerMoose::MoveAntlerLock(bool activated)
{
	m_cAntlerMooseLock->Set(activated);
}
