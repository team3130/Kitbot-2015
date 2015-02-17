#include "AutonIntakeArms.h"

AutonIntakeArms::AutonIntakeArms()
	: m_waitTime(0)
{
	Requires(intakearms);
	timer = new Timer();
}

// Called just before this Command runs the first time
void AutonIntakeArms::Initialize()
{
	intakearms->ControlArms(true, true);
	timer->Reset();
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void AutonIntakeArms::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool AutonIntakeArms::IsFinished()
{
	return (timer->Get() > m_waitTime);
}

// Called once after isFinished returns true
void AutonIntakeArms::End()
{
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonIntakeArms::Interrupted()
{
}
