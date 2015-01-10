#include "ControlLifter.h"

ControlLifter::ControlLifter()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(lifter);
	m_nMoveDirection = 0;
}

// Called just before this Command runs the first time
void ControlLifter::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ControlLifter::Execute()
{
	//lifter->Move(oi->stickL,oi->stickR);
	if(oi->gamepad->GetRawButton(B_LIFTERUP))
	{
		m_nMoveDirection = 1;
	}
	else if(oi->gamepad->GetRawButton(B_LIFTERDOWN))
	{
		m_nMoveDirection = -1;
	}
	else{m_nMoveDirection = 0;}
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
