#include "AutonRollers.h"

AutonRollers::AutonRollers()
	: m_waitTime(0)
	, m_nLeftIntake(0)
	, m_nRightIntake(0)
{
	Requires(intake);
	timer = new Timer();
}



// Called just before this Command runs the first time
void AutonRollers::Initialize()
{
	intake->HandleObjects(m_nLeftIntake, m_nRightIntake);
	timer->Reset();
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void AutonRollers::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool AutonRollers::IsFinished()
{
	return (timer->Get() > m_waitTime);
}

// Called once after isFinished returns true
void AutonRollers::End()
{
	intake->HandleObjects(0, 0);	//idles rollers to end
	timer->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonRollers::Interrupted()
{
	End();
}
