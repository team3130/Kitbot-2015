#include "ExampleCommand.h"

ExampleCommand::ExampleCommand()
	: m_bGyroMode(false)
{
	Requires(chassis);
}

// Called just before this Command runs the first time
void ExampleCommand::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ExampleCommand::Execute()
{
	double moveSpeed = CommandBase::oi->stickL->GetY();
	double moveTurn = CommandBase::oi->stickR->GetX();
	double speedMultiplier = (-0.5 * CommandBase::oi->stickL->GetZ()) + 0.5;
	double turnMultiplier = (-0.5 * CommandBase::oi->stickR->GetZ()) + 0.5;
	if(moveTurn < 0.03 and moveTurn > -0.03) {
		if(m_bGyroMode) {
			chassis->GyroDrive(moveSpeed * speedMultiplier);
		}else{
			m_bGyroMode = true;
			chassis->HoldAngle(chassis->GetAngle());
		}
	}else{
		m_bGyroMode = false;
		chassis->Drive(moveSpeed * speedMultiplier, moveTurn * turnMultiplier);
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ExampleCommand::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ExampleCommand::End()
{
	chassis->Drive(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ExampleCommand::Interrupted()
{
	End();
}
