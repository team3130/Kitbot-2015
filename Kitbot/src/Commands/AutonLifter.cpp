#include "AutonLifter.h"

AutonLifter::AutonLifter()
	: m_waitTime(0)
	, m_dThreshold(0)
	, m_dEncoderGoal(0)
	, m_Push(kNone)
	, m_bPusherDone(true)
{
	Requires(lifter);
	Requires(pusher);
	timer = new Timer();
}

// Called just before this Command runs the first time
void AutonLifter::Initialize()
{
	lifter->toSetpoint(m_dEncoderGoal);
	if(m_Push == kNone) {
		m_bPusherDone = true;
	}
	else {
		m_bPusherDone = false;
		pusher->pushLifter( m_Push==kIn ? 1.0 : -1.0 );
	}
	timer->Reset();
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void AutonLifter::Execute()
{
	if(	(m_Push == kIn && pusher->GetLimitSwitchIn()) ||
		(m_Push == kOut && pusher->GetLimitSwitchOut()) ) {
		pusher->pushLifter(0);
		m_bPusherDone = true;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool AutonLifter::IsFinished()
{
	if(timer->Get() > m_waitTime) return true;
	return (
			(	fabs(lifter->GetPosition() - m_dEncoderGoal) < m_dThreshold
				|| !lifter->GetLimitSwitchTop()
				|| !lifter->GetLimitSwitchBot()	)
			&& m_bPusherDone );
}

// Called once after isFinished returns true
void AutonLifter::End()
{
	lifter->moveLifter(0);
	pusher->pushLifter(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonLifter::Interrupted()
{
	End();
}
