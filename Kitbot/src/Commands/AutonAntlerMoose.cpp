#include "AutonAntlerMoose.h"

AutonAntlerMoose::AutonAntlerMoose()
{
	Requires(antlerMoose);
	m_bAntlerMooseExecute = false;
	m_bRan = false;
	timer = new Timer;
	timer->Reset();
}

// Called just before this Command runs the first time
void AutonAntlerMoose::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void AutonAntlerMoose::Execute()
{
	if(m_bAntlerMooseExecute){
		antlerMoose->ControlAntlers(1);
		m_bRan = true;
		timer->Start();
	}
}

// Make this return true when this Command no longer needs to run execute()
bool AutonAntlerMoose::IsFinished()
{
	return (m_bRan and timer->Get() > 0.5);
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
