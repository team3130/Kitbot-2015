#include "ControlMooseLifter.h"

ControlMooseLifter::ControlMooseLifter()
	: m_bMooseUp(false)
	, m_bFinished(false)
{
	Requires(mooseLifter);
}

// Called just before this Command runs the first time
void ControlMooseLifter::Initialize()
{
	m_bFinished = false;
	m_bMooseUp = !m_bMooseUp;
	mooseLifter->MoveMooseLifterSolenoid(m_bMooseUp);
}

// Called repeatedly when this Command is scheduled to run
void ControlMooseLifter::Execute()
{
	if(m_bMooseUp)
	{
		if(mooseLifter->isHighEnough())
		{
			mooseLifter->MoveMooseLock(true);
			m_bFinished = true;
		}
	}
	else
	{
		m_bFinished = true;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ControlMooseLifter::IsFinished()
{
	return m_bFinished;
}

// Called once after isFinished returns true
void ControlMooseLifter::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ControlMooseLifter::Interrupted()
{

}
