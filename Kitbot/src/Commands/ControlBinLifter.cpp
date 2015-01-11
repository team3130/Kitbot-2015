#include "ControlBinLifter.h"

ControlBinLifter::ControlBinLifter()
{
	Requires(binintake);
}

// Called just before this Command runs the first time
void ControlBinLifter::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ControlBinLifter::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool ControlBinLifter::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ControlBinLifter::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ControlBinLifter::Interrupted()
{

}
