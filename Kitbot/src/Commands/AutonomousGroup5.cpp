#include "AutonomousGroup5.h"

AutonomousGroup5::AutonomousGroup5()
{

}

AutonomousGroup5::~AutonomousGroup5()
{
}

// Called just before this Command runs the first time
void AutonomousGroup5::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void AutonomousGroup5::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool AutonomousGroup5::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void AutonomousGroup5::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonomousGroup5::Interrupted()
{
	End();
}
