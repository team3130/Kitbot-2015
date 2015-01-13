#include "ControlBinIntake.h"

ControlBinIntake::ControlBinIntake()
{
	Requires(intake);
}

// Called just before this Command runs the first time
void ControlBinIntake::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ControlBinIntake::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool ControlBinIntake::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ControlBinIntake::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ControlBinIntake::Interrupted()
{

}
