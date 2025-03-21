#include "AutonDumbDrive.h"

AutonDumbDrive::AutonDumbDrive()
	: m_waitTime(0)
	, m_driveSpeed(0)
{
	Requires(chassis);
	timer = new Timer();
}

// Called just before this Command runs the first time
void AutonDumbDrive::Initialize()
{
	timer->Reset();
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void AutonDumbDrive::Execute()
{
	chassis->Drive(m_driveSpeed, 0);	//starts driving backwards for a time
}

// Make this return true when this Command no longer needs to run execute()
bool AutonDumbDrive::IsFinished()
{
	return (timer->Get() > m_waitTime);
}

// Called once after isFinished returns true
void AutonDumbDrive::End()
{
	chassis->Drive(0, 0);	//stops driving
	timer->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonDumbDrive::Interrupted()
{
	End();
}
