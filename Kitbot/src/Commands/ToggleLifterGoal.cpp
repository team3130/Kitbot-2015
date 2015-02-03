#include "ToggleLifterGoal.h"

ToggleLifterGoal::ToggleLifterGoal()
{
	//Don't want to monopolize the lifter subsystem to toggle between
	//using manual control and preset lifter goals
}

// Called just before this Command runs the first time
void ToggleLifterGoal::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ToggleLifterGoal::Execute()
{
	CommandBase::lifter->SwitchManualControl();
}

// Make this return true when this Command no longer needs to run execute()
bool ToggleLifterGoal::IsFinished()
{
	return true;		//should finish immediately
}

// Called once after isFinished returns true
void ToggleLifterGoal::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ToggleLifterGoal::Interrupted()
{

}
