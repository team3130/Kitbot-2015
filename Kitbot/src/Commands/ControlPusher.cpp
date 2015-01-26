#include "ControlPusher.h"

ControlPusher::ControlPusher()
{
	Requires(pusher);
}

// Called just before this Command runs the first time
void ControlPusher::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ControlPusher::Execute()
{
	pusher->pushLifter(oi->gamepad->GetRawAxis(A_PUSHER));
}

// Make this return true when this Command no longer needs to run execute()
bool ControlPusher::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ControlPusher::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ControlPusher::Interrupted()
{

}
