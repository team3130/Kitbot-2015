#include "ControlRollers.h"

ControlRollers::ControlRollers()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void ControlRollers::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ControlRollers::Execute()
{
	chassis->Drive(oi->stickL,oi->stickR);
}

// Make this return true when this Command no longer needs to run execute()
bool ControlRollers::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ControlRollers::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ControlRollers::Interrupted()
{

}
