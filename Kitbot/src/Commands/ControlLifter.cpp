#include "ControlLifter.h"

ControlLifter::ControlLifter()
	: manualMode(true)
	, goal(0)
{
	Requires(lifter);
}

// Called just before this Command runs the first time
void ControlLifter::Initialize()
{
	goal = 0; //default goal at bottom
	manualMode = true;
}

// Called repeatedly when this Command is scheduled to run
void ControlLifter::Execute()
{
	double thumb = -oi->gamepad->GetRawAxis(A_LIFTER);
	if(fabs(thumb) > 0.1)
	{
		manualMode = true;
		lifter->moveLifter(thumb);
	}
	else if(manualMode)
	{
		lifter->moveLifter(0);
	}

	if(oi->gamepad->GetRawButton(B_PAD_A)){
		goal = 0;
		manualMode = false;
	} else if(oi->gamepad->GetRawButton(B_PAD_B)){
		goal = 1;
		manualMode = false;
	} else if(oi->gamepad->GetRawButton(B_PAD_X)){
		goal = 2;
		manualMode = false;
	} else if(oi->gamepad->GetRawButton(B_PAD_Y)){
		goal = 3;
		manualMode = false;
	}

	if(!manualMode)
	{
		lifter->toSetpoint(goal);
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
