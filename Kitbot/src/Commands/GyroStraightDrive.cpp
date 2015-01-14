#include "GyroStraightDrive.h"

GyroStraightDrive::GyroStraightDrive()
{
	// Use Requires() here to declare subsystem dependencies
	Requires(chassis);
}

// Called just before this Command runs the first time
void GyroStraightDrive::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void GyroStraightDrive::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool GyroStraightDrive::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void GyroStraightDrive::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GyroStraightDrive::Interrupted()
{

}
