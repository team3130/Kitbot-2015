#include "ResetLifter.h"

ResetLifter::ResetLifter()
{
	Requires(lifter);
}

// Called just before this Command runs the first time
void ResetLifter::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ResetLifter::Execute()
{
	//lifter->Move(oi->stickL,oi->stickR);
	lifter->moveLifter(-1);
}

// Make this return true when this Command no longer needs to run execute()
bool ResetLifter::IsFinished()
{
	return lifter->GetLimitSwitchBot();
}

// Called once after isFinished returns true
void ResetLifter::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ResetLifter::Interrupted()
{

}
