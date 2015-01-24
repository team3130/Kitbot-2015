#include "ControlIntakeArms.h"

ControlIntakeArms::ControlIntakeArms()
{
	Requires(intakearms);
	m_bArmsExtended = false;
}

// Called just before this Command runs the first time
void ControlIntakeArms::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ControlIntakeArms::Execute()
{
	intakearms->ControlArms(m_bArmsExtended);
}

// Make this return true when this Command no longer needs to run execute()
bool ControlIntakeArms::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ControlIntakeArms::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ControlIntakeArms::Interrupted()
{

}
