#include "ExampleCommand.h"

ExampleCommand::ExampleCommand()
	: m_bGyroMode(false)
	, m_bGyroPrep(true)
	, m_GyroTimer()
{
	Requires(chassis);
}

// Called just before this Command runs the first time
void ExampleCommand::Initialize()
{
	chassis->HoldAngle(chassis->GetAngle());
	m_GyroTimer.Reset();
	m_bGyroMode = false;
	m_bGyroPrep = true;
}

// Called repeatedly when this Command is scheduled to run
void ExampleCommand::Execute()
{
	double moveSpeed = CommandBase::oi->stickL->GetY();
	double moveTurn = CommandBase::oi->stickR->GetX();
	double speedMultiplier = (-0.5 * CommandBase::oi->stickL->GetZ()) + 0.5;
	double turnMultiplier = (-0.5 * CommandBase::oi->stickR->GetZ()) + 0.5;

	if(fabs(moveTurn) > 0.1) {
		m_bGyroMode = false;
		m_bGyroPrep = true;
	}
	else if(m_bGyroPrep) {
		m_GyroTimer.Reset();
		m_GyroTimer.Start();
		m_bGyroPrep = false;
	}
	else if(m_GyroTimer.Get() > 2.0 && !m_bGyroMode){
		m_bGyroMode = true;
		chassis->HoldAngle(chassis->GetAngle());
	}

	if(m_bGyroMode) {
		chassis->GyroDrive(moveSpeed * speedMultiplier);
	} else {
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
