#include "AutonLifter.h"

AutonLifter::AutonLifter()
{
	Requires(lifter);
	m_nLifterDirection = 0;
	m_bLifterExecute = false;
}

// Called just before this Command runs the first time
void AutonLifter::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void AutonLifter::Execute()
{
	if(m_bLifterExecute){
		lifter->moveLifter(m_nLifterDirection);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool AutonLifter::IsFinished()
{
	if(m_nLifterDirection > 0){
		m_bLifterExecute = false;
		return CommandBase::lifter->GetLimitSwitchTop();
	}else if(m_nLifterDirection < 0){
		m_bLifterExecute = false;
		return CommandBase::lifter->GetLimitSwitchTop();
	}else{
		return false;
	}
}

// Called once after isFinished returns true
void AutonLifter::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonLifter::Interrupted()
{

}
