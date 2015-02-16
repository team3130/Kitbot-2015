#include "AutonAntlerMoose.h"

AutonAntlerMoose::AutonAntlerMoose()
{
	Requires(antlerMoose);
	m_bAntlerMooseExecute = false;
	m_bLockDisabled = false;
	m_bRan = false;
}

// Called just before this Command runs the first time
void AutonAntlerMoose::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void AutonAntlerMoose::Execute()
{
	if(m_bAntlerMooseExecute){
		antlerMoose->ControlAntlers(true);
		m_bRan = true;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool AutonAntlerMoose::IsFinished()
{
	return m_bRan;
}

// Called once after isFinished returns true
void AutonAntlerMoose::End()
{
	m_bAntlerMooseExecute = false;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonAntlerMoose::Interrupted()
{

}
