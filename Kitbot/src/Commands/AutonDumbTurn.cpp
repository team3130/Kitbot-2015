#include "AutonDumbTurn.h"

AutonDumbTurn::AutonDumbTurn()
	: m_waitTime(0)
	, m_driveTurn(0)
{
	Requires(chassis);
	timer = new Timer();
}

// Called just before this Command runs the first time
void AutonDumbTurn::Initialize()
{
	chassis->Drive(0, m_driveTurn);	//starts driving backwards for a time
	timer->Reset();
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void AutonDumbTurn::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool AutonDumbTurn::IsFinished()
{
	return (timer->Get() > m_waitTime);
}

// Called once after isFinished returns true
void AutonDumbTurn::End()
{
	chassis->Drive(0, 0);	//stops driving
	timer->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonDumbTurn::Interrupted()
{
	End();
}
