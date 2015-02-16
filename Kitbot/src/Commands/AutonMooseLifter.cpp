#include "AutonMooseLifter.h"

AutonMooseLifter::AutonMooseLifter()
{
	Requires(mooseLifter);
	m_bMooseExecute = false;
	m_bMooseOn = true;
	m_bRan = false;
	timer = new Timer;
}

// Called just before this Command runs the first time
void AutonMooseLifter::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void AutonMooseLifter::Execute()
{
	if(m_bMooseExecute){
		mooseLifter->MoveMooseLifterSolenoid(m_bMooseOn);
		m_bRan = true;
		timer->Reset();
		timer->Start();
	}
}
// Make this return true when this Command no longer needs to run execute()
bool AutonMooseLifter::IsFinished()
{
	return (m_bRan and timer->Get() > 0.5);
}

// Called once after isFinished returns true
void AutonMooseLifter::End()
{
	m_bMooseExecute = false;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonMooseLifter::Interrupted()
{

}
