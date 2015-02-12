#include "ControlAntlerMoose.h"

ControlAntlerMoose::ControlAntlerMoose()
{
	Requires(antlerMoose);
	m_Button = new JoystickButton(oi->gamepad, 7);
}

ControlAntlerMoose::~ControlAntlerMoose()
{
	delete m_Button;
}

// Called just before this Command runs the first time
void ControlAntlerMoose::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ControlAntlerMoose::Execute()
{
	antlerMoose->MoveAntlerLock(m_Button->Get());
}

// Make this return true when this Command no longer needs to run execute()
bool ControlAntlerMoose::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ControlAntlerMoose::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ControlAntlerMoose::Interrupted()
{

}
