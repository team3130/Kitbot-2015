#include "AutonPusher.h"

AutonPusher::AutonPusher()
{
	Requires(pusher);
	m_bPusherExecute = false;
	m_fDirection = 0;
}

// Called just before this Command runs the first time
void AutonPusher::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void AutonPusher::Execute()
{
	if(m_bPusherExecute){
		pusher->pushLifter(m_fDirection);
	}

}

// Make this return true when this Command no longer needs to run execute()
bool AutonPusher::IsFinished()
{
	if(m_fDirection > 0){
		return pusher->GetLimitSwitchOut();
	}else if(m_fDirection){
		return pusher->GetLimitSwitchIn();
	}else{
		return false;
	}
}

// Called once after isFinished returns true
void AutonPusher::End()
{
	m_bPusherExecute = false;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonPusher::Interrupted()
{

}
