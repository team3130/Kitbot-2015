#include "PusherLED.h"

PusherLED::PusherLED()
{
}

// Called just before this Command runs the first time
void PusherLED::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void PusherLED::Execute()
{
	if(!CommandBase::pusher->GetLimitSwitchIn()){
		CommandBase::pusher->SwitchLED(true);
	}else{
		CommandBase::pusher->SwitchLED(false);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool PusherLED::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void PusherLED::End()
{
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PusherLED::Interrupted()
{
	End();
}
