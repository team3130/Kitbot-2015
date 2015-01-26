#include "ResetPusher.h"

ResetPusher::ResetPusher()
{
	Requires(pusher);
}

// Called just before this Command runs the first time
void ResetPusher::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ResetPusher::Execute()
{
	//lifter->Move(oi->stickL,oi->stickR);
	pusher->pushLifter(-1);
}

// Make this return true when this Command no longer needs to run execute()
bool ResetPusher::IsFinished()
{
	return pusher->GetLimitSwitchIn();
}

// Called once after isFinished returns true
void ResetPusher::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ResetPusher::Interrupted()
{

}
