#include "ControlLifter.h"

ControlLifter::ControlLifter()
{
	Requires(lifter);
}

// Called just before this Command runs the first time
void ControlLifter::Initialize()
{
	goal = 0; //default goal
}

// Called repeatedly when this Command is scheduled to run
void ControlLifter::Execute()
{
	if(lifter->GetManualControl()){
		lifter->moveLifter(-oi->gamepad->GetRawAxis(A_LIFTER));
	}else{
		if(oi->gamepad->GetRawAxis(A_GOALSET1) == 1 && oi->gamepad->GetRawAxis(A_GOALSET2) == 0){
			goal = 1;
		}
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ControlLifter::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ControlLifter::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ControlLifter::Interrupted()
{

}
