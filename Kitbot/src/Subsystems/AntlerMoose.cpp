#include <Commands/AutonAntlerMoose.h>
#include "AntlerMoose.h"
#include "../RobotMap.h"

AntlerMoose::AntlerMoose()
	: Subsystem("AntlerMoose")
{
	m_cAntlerMooseLock = new Solenoid(ANTLERMOOSELOCK);
}

AntlerMoose::~AntlerMoose(){
	delete m_cAntlerMooseLock;
}

void AntlerMoose::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new AutonAntlerMoose());
}
