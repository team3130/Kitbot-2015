#include "AutonLifter.h"

AutonLifter::AutonLifter()
{
	Requires(lifter);
	m_bLifterExecute = false;
	m_b2StageOn = true;
	m_bStage1Done = false;
	m_bStage2Done = false;
}

// Called just before this Command runs the first time
void AutonLifter::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void AutonLifter::Execute()
{
	if(m_bLifterExecute){
		if(!m_bStage1Done){
			lifter->moveLifter(-1);
			if(lifter->GetLimitSwitchBot()){
				m_bStage1Done = true;
			}
		}else if(m_b2StageOn){
			lifter->moveLifter(1);
			if(lifter->GetLimitSwitchTop()){
				m_bStage2Done = true;
			}
		}
	}
}

// Make this return true when this Command no longer needs to run execute()
bool AutonLifter::IsFinished()
{
	if(m_b2StageOn and m_bStage2Done){
		return true;
	}else if(!m_b2StageOn and m_bStage1Done){
		return true;
	}else{
		return false;
	}
}

// Called once after isFinished returns true
void AutonLifter::End()
{
	m_bLifterExecute = false;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonLifter::Interrupted()
{
	End();
}
