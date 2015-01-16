#include "StepEjection.h"

StepEjection::StepEjection()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(chassis);
}

// Called just before this Command runs the first time
void StepEjection::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void StepEjection::Execute()
{
	chassis->Drive(oi->stickL,oi->stickR);
}

// Make this return true when this Command no longer needs to run execute()
bool StepEjection::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void StepEjection::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void StepEjection::Interrupted()
{

}
