#include "AutonBincher.h"

AutonBincher::AutonBincher()
{
	Requires(bincher);
	m_bRan = false;
}

AutonBincher::~AutonBincher()
{
}

// Called just before this Command runs the first time
void AutonBincher::Initialize()
{
	bincher->SetPinch(m_bDirection);
	m_bRan = true;
}

// Called repeatedly when this Command is scheduled to run
void AutonBincher::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool AutonBincher::IsFinished()
{
	return m_bRan;
}

// Called once after isFinished returns true
void AutonBincher::End()
{
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonBincher::Interrupted()
{
	End();
}
