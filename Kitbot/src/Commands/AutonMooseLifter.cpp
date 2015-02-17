#include "AutonMooseLifter.h"

AutonMooseLifter::AutonMooseLifter()
	: m_waitTime(0)
	, m_distance(0)
	, m_bMooseUp(true)
	, m_bDone(false)
	, timer(new Timer())
{
	Requires(mooseLifter);
}

// Called just before this Command runs the first time
void AutonMooseLifter::Initialize()
{
	m_bDone = false;
}

// Called repeatedly when this Command is scheduled to run
void AutonMooseLifter::Execute()
{
	if(!m_bDone) {
		if(m_distance == 0
				|| (m_distance > 0 && chassis->GetDistance() >= m_distance)
				|| (m_distance < 0 && chassis->GetDistance() <= m_distance))
		{
			mooseLifter->MoveMooseLifterSolenoid(m_bMooseUp);
			m_bDone = true;
			timer->Reset();
			timer->Start();
		}
	}
}
// Make this return true when this Command no longer needs to run execute()
bool AutonMooseLifter::IsFinished()
{
	return (m_bDone and timer->Get() > m_waitTime);
}

// Called once after isFinished returns true
void AutonMooseLifter::End()
{
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonMooseLifter::Interrupted()
{
}
