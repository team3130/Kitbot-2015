#include "AutonAntlerMoose.h"

AutonAntlerMoose::AutonAntlerMoose()
	: m_waitTime(0)
{
	Requires(antlerMoose);
	timer = new Timer();
}

// Called just before this Command runs the first time
void AutonAntlerMoose::Initialize()
{
	antlerMoose->ControlLeftAntler(DoubleSolenoid::kReverse);
	antlerMoose->ControlRightAntler(DoubleSolenoid::kReverse);
	timer->Reset();
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void AutonAntlerMoose::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool AutonAntlerMoose::IsFinished()
{
	return (timer->Get() > m_waitTime);
}

// Called once after isFinished returns true
void AutonAntlerMoose::End()
{
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonAntlerMoose::Interrupted()
{
}
