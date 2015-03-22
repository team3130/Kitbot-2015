#include "AutonDelay.h"

AutonDelay::AutonDelay()
	: m_waitTime(0)
{
	timer = new Timer();
}

// Called just before this Command runs the first time

void AutonDelay::SetWait(double delay){
	m_waitTime = delay;
}
void AutonDelay::Initialize()
{
	timer->Reset();
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void AutonDelay::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool AutonDelay::IsFinished()
{
	return timer->Get() > m_waitTime;
}

// Called once after isFinished returns true
void AutonDelay::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonDelay::Interrupted()
{
	End();
}
