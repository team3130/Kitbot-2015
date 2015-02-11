#include "ControlAntlerMoose.h"

ControlAntlerMoose::ControlAntlerMoose()
{
	Requires(antlerMoose);
}

// Called just before this Command runs the first time
void ControlAntlerMoose::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ControlAntlerMoose::Execute()
{
	antlerMoose->MoveAntlerLock();
}

// Make this return true when this Command no longer needs to run execute()
bool ControlAntlerMoose::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ControlAntlerMoose::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ControlAntlerMoose::Interrupted()
{

}
