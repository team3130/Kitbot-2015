#include "AutonSmartTurn.h"

AutonSmartTurn::AutonSmartTurn()
{
	Requires(chassis);
	cTimer = new Timer();
}

// Called just before this Command runs the first time
void AutonSmartTurn::Initialize()
{
	CommandBase::chassis->HoldAngle(dAngle);
	CommandBase::chassis->GyroDrive(0);
}

// Called repeatedly when this Command is scheduled to run
void AutonSmartTurn::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool AutonSmartTurn::IsFinished()
{
	return ((CommandBase::chassis->OnTarget()) or (cTimer.Get() > dTimeout));
}

// Called once after isFinished returns true
void AutonSmartTurn::End()
{
	CommandBase::chassis->ReleaseAngle();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonSmartTurn::Interrupted()
{
	End();
}
