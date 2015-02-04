#include "ControlMooseLifter.h"

ControlMooseLifter::ControlMooseLifter()
{
	Requires(mooseLifter);
}

// Called just before this Command runs the first time
void ControlMooseLifter::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ControlMooseLifter::Execute()
{
	mooseLifter->MoveMooseLifterSolenoid();
}

// Make this return true when this Command no longer needs to run execute()
bool ControlMooseLifter::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void ControlMooseLifter::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ControlMooseLifter::Interrupted()
{

}
