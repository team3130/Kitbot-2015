#include "SavePreferences.h"

SavePreferences::SavePreferences()
{
	this->SetRunWhenDisabled(true);
}

// Called just before this Command runs the first time
void SavePreferences::Initialize()
{
	Preferences::GetInstance()->Save();
}

// Called repeatedly when this Command is scheduled to run
void SavePreferences::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool SavePreferences::IsFinished()
{
	return true;
}

// Called once after isFinished returns true
void SavePreferences::End()
{
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SavePreferences::Interrupted()
{
	End();
}
