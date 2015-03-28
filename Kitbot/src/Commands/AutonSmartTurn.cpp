#include "AutonSmartTurn.h"

AutonSmartTurn::AutonSmartTurn()
	: m_dTimeout(0)
	, m_dAngle(0)
	, m_dDriveSpeed(0)
	, m_dDistGoal(0)
	, m_dTolerance(0)
{
	Requires(chassis);
}

// Called just before this Command runs the first time
void AutonSmartTurn::Initialize()
{
	m_cTimer.Reset();
	CommandBase::chassis->HoldAngle(m_dAngle);
	CommandBase::chassis->GyroDrive(0, false);
	m_cTimer.Start();
}

// Called repeatedly when this Command is scheduled to run
void AutonSmartTurn::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool AutonSmartTurn::IsFinished()
{
	return( fabs(CommandBase::chassis->GetPosition() - CommandBase::chassis->GetSetpoint()) < m_dTolerance
	or m_cTimer.Get() > m_dTimeout );
}

// Called once after isFinished returns true
void AutonSmartTurn::End()
{
	CommandBase::chassis->ReleaseAngle();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonSmartTurn::Interrupted()
{
	End();
}
