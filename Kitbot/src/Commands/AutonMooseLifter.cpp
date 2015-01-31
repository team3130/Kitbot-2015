#include "AutonMooseLifter.h"

AutonMooseLifter::AutonMooseLifter()
{
	Requires(mooseLifter);
	m_bMooseExecute = false;
	m_bMooseOn = true;
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
	}
}
// Make this return true when this Command no longer needs to run execute()
bool AutonMooseLifter::IsFinished()
{
	if(m_bMooseExecute and m_bMooseOn){
		return mooseLifter->GetLimitSwitchBot();
	}else if(m_bMooseExecute and !m_bMooseOn){
		return mooseLifter->GetLimitSwitchTop();
	}else{
		return false;
	}
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
