#include "ExampleCommand.h"

ExampleCommand::ExampleCommand()
{
	Requires(chassis);
}

// Called just before this Command runs the first time
void ExampleCommand::Initialize()
{
	chassis->Drive(0,0);
}

// Called repeatedly when this Command is scheduled to run
void ExampleCommand::Execute()
{
	double moveSpeed = CommandBase::oi->stickL->GetY();
	double moveTurn = CommandBase::oi->stickL->GetX();
	double speedMultiplier = (-0.5 * CommandBase::oi->stickL->GetZ()) + 0.5;
	double turnMultiplier = (-0.5 * CommandBase::oi->stickL->GetZ()) + 0.5;

	// Only driving manual should require Quadratic inputs. By default it should be turned off
	// Therefore here we turn it on explicitly.
	chassis->Drive(moveSpeed * speedMultiplier, moveTurn * turnMultiplier, true);
	return;
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
