#include "ControlLifter.h"

ControlLifter::ControlLifter()
{
	Requires(lifter);
}

// Called just before this Command runs the first time
void ControlLifter::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ControlLifter::Execute()
{
	lifter->moveLifter(-oi->gamepad->GetRawAxis(A_LIFTER));
}

// Make this return true when this Command no longer needs to run execute()
bool ControlLifter::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ControlLifter::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ControlLifter::Interrupted()
{

}
