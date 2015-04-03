#include "ControlMooseLifter.h"

ControlMooseLifter::ControlMooseLifter()
	: m_bWatchLoop(false)
	, m_bNewStatus(true)
{
	Requires(mooseLifter);
	m_Button = new JoystickButton(oi->gamepad, 8);
}

ControlMooseLifter::~ControlMooseLifter()
{
	delete m_Button;
}

// Called just before this Command runs the first time
void ControlMooseLifter::Initialize()
{
	m_bNewStatus = true;
	m_bWatchLoop = mooseLifter->isUp();
	//mooseLifter->MoveMooseLifterSolenoid(false);
	mooseLifter->RestoreLifterSolenoid();

}

// Called repeatedly when this Command is scheduled to run
void ControlMooseLifter::Execute()
{
	if(m_bWatchLoop) {
		if(mooseLifter->isUp() &&  mooseLifter->isHighEnough())
		{
				mooseLifter->MoveMooseLock(true);
				m_bWatchLoop = false;
		}
	}

	if(m_Button->Get())
	{
		if(m_bNewStatus) {
			m_bNewStatus = false;
			if(mooseLifter->isUp()) {
				mooseLifter->MoveMooseLifterSolenoid(false);
			}
			else {
				m_bWatchLoop = true;
				mooseLifter->MoveMooseLifterSolenoid(true);
			}
			mooseLifter->MoveMooseLock(false);
		}
	}
	else
	{
		m_bNewStatus = true;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ControlMooseLifter::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ControlMooseLifter::End()
{
	mooseLifter->MoveMooseLock(true);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ControlMooseLifter::Interrupted()
{
	End();
}
