#include "AutonomousGroupReload.h"

AutonomousGroupReload::AutonomousGroupReload()
{
	m_cAutonLifterUp = new AutonLifter();
	m_cAutonLifterDown = new AutonLifter();
	
	AddSequential(m_cAutonLifterDown);
	AddSequential(new WaitCommand(0.15));
	AddSequential(m_cAutonLifterUp);
}

AutonomousGroupReload::~AutonomousGroupReload()
{
	delete m_cAutonLifterUp;
	delete m_cAutonLifterDown;
}

// Called just before this Command runs the first time
void AutonomousGroupReload::Initialize()
{
}

void AutonomousGroupReload::SetGoal(double endingHeight)
{
	m_cAutonLifterDown->SetGoal(2, 25, 0);	// All the way down to pickup the tote
	m_cAutonLifterUp->SetGoal(2, 25, endingHeight);	// Up to the ordered height
}

// Called repeatedly when this Commsand is scheduled to run
void AutonomousGroupReload::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool AutonomousGroupReload::IsFinished()
{
	return m_cAutonLifterUp->IsFinished();
}

// Called once after isFinished returns true
void AutonomousGroupReload::End()
{
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonomousGroupReload::Interrupted()
{
	End();
}
