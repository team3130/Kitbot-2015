#include "ControlPusher.h"

ControlPusher::ControlPusher()
	: manualMode(true)
{
	Requires(pusher);
}

// Called just before this Command runs the first time
void ControlPusher::Initialize()
{
	manualMode = true;
	pusher->pushLifter(0);
}

// Called repeatedly when this Command is scheduled to run
void ControlPusher::Execute()
{
	double thumb = oi->gamepad->GetRawAxis(A_PUSHER);
	double direc = oi->gamepad->GetPOV(POV_PUSHER_EXTREMES);
	if(fabs(thumb) > 0.1){
		manualMode = true;
		pusher->pushLifter(thumb);
	}else if(direc == 0){
		manualMode = false;
		pusher->pushLifter(-1);	//continues to go out
	}else if(direc == 180){
		manualMode = false;
		pusher->pushLifter(1);	//continues to go in
	}else if(manualMode){
		pusher->pushLifter(0);		//only stops pusher if manual control activates
	}

	if(pusher->GetLimitSwitchOut()){
		pusher->SwitchLED(false);
		if(!manualMode) {
			manualMode = true;
			pusher->pushLifter(0);
		}
	}else{
		pusher->SwitchLED(true);
	}

	if(pusher->GetLimitSwitchIn()){
		if(!manualMode) {
			pusher->pushLifter(0);
			manualMode = true;
		}
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ControlPusher::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ControlPusher::End()
{
	pusher->pushLifter(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ControlPusher::Interrupted()
{
	End();
}
