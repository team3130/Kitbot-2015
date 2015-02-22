#include "AutonLifter.h"

AutonLifter::AutonLifter()
	: m_waitTime(0)
	, m_dEncoderGoal(0)
{
	Requires(lifter);
	timer = new Timer();
}

// Called just before this Command runs the first time
void AutonLifter::Initialize()
{
	lifter->toSetpoint(m_dEncoderGoal);
	timer->Reset();
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void AutonLifter::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool AutonLifter::IsFinished()
{
	return (lifter->GetPosition() == m_dEncoderGoal || timer->Get() > m_waitTime ||
			!lifter->GetLimitSwitchTop() || !lifter->GetLimitSwitchBot());
}

// Called once after isFinished returns true
void AutonLifter::End()
{
	lifter->moveLifter(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonLifter::Interrupted()
{
	End();
}
