#include "AutonPusher.h"

AutonPusher::AutonPusher()
	: m_waitTime(0)
	, m_nDirection(0)
{
	Requires(pusher);
	timer = new Timer();
	timer2 = new Timer();
}

// Called just before this Command runs the first time
void AutonPusher::Initialize()
{
	pusher->pushLifter(m_nDirection);
	timer->Reset();
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void AutonPusher::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool AutonPusher::IsFinished()
{
	return (timer->Get() > m_waitTime ||
			(m_nDirection == 1 && pusher->GetLimitSwitchIn()) ||
			(m_nDirection == -1 && pusher->GetLimitSwitchOut()));
}

// Called once after isFinished returns true
void AutonPusher::End()
{
	pusher->pushLifter(0);
	timer->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonPusher::Interrupted()
{
	End();
}
