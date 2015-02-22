#include "AutonTurn.h"

AutonTurn::AutonTurn()
	: m_angle(0)
	, m_waitTime(0)
{
	Requires(chassis);
	timer = new Timer();
}

// Called just before this Command runs the first time
void AutonTurn::Initialize()
{
	chassis->HoldAngle(m_angle);	//Holds the specified angle so the robot will turn towards it
	timer->Reset();
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void AutonTurn::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool AutonTurn::IsFinished()
{
	return (timer->Get() > m_waitTime);
}

// Called once after isFinished returns true
void AutonTurn::End()
{
	chassis->ReleaseAngle();	//stops holding the angle
	timer->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonTurn::Interrupted()
{
	End();
}
