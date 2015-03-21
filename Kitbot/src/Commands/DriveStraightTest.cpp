#include "DriveStraightTest.h"

DriveStraightTest::DriveStraightTest()
{
	Requires(chassis);
}

// Called just before this Command runs the first time
void DriveStraightTest::Initialize()
{
	CommandBase::chassis->HoldAngle(0);
}

// Called repeatedly when this Command is scheduled to run
void DriveStraightTest::Execute()
{
	double moveSpeed = CommandBase::oi->stickL->GetY();
	double speedMultiplier = (-0.5 * CommandBase::oi->stickL->GetZ()) + 0.5;
	CommandBase::chassis->GyroDrive(moveSpeed * speedMultiplier);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveStraightTest::IsFinished()
{
	return !oi->straightTest->Get();
}

// Called once after isFinished returns true
void DriveStraightTest::End()
{
	CommandBase::chassis->ReleaseAngle();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveStraightTest::Interrupted()
{
	End();
}
