#include <Commands/AutonAntlerMoose.h>
#include "AntlerMoose.h"
#include "../RobotMap.h"

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
	// Set the default command for a subsystem here.

}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void AntlerMoose::MoveAntlerLock()
{
	m_bActivated = !m_bActivated;
	m_cAntlerMooseLock->Set(m_bActivated);
}
