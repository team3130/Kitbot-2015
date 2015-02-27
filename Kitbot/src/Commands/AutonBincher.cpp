#include "AutonBincher.h"

AutonBincher::AutonBincher()
{
	Requires(bincher);
}

AutonBincher::~AutonBincher()
{
}

// Called just before this Command runs the first time
void AutonBincher::Initialize()
{
	bincher->SetPinch(m_bDirection);
}

// Called repeatedly when this Command is scheduled to run
void AutonBincher::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool AutonBincher::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void AutonBincher::End()
{
	bincher->SetPinch(false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonBincher::Interrupted()
{
	End();
}
