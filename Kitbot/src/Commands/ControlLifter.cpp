#include "ControlLifter.h"

ControlLifter::ControlLifter()
{
	Requires(lifter);
	goal = 0;
}

// Called just before this Command runs the first time
void ControlLifter::Initialize()
{
	goal = 0; //default goal at bottom
}

// Called repeatedly when this Command is scheduled to run
void ControlLifter::Execute()
{
	lifter->moveLifter(-oi->gamepad->GetRawAxis(A_LIFTER));
	if(oi->gamepad->GetRawButton(B_LIFTERGOAL1)){
		goal = 0;
	}else if(oi->gamepad->GetRawButton(B_LIFTERGOAL2)){
		goal = 1;
	}else if(oi->gamepad->GetRawButton(B_LIFTERGOAL3)){
		goal = 2;
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
	lifter->moveLifter(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ControlLifter::Interrupted()
{
	End();
}
