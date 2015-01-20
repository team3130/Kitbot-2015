#include "AutonomousGroup.h"

AutonomousGroup::AutonomousGroup()
{
	m_cAutonRollers = new ControlRollers();
	m_cAutonLifter = new ControlLifter();
}

AutonomousGroup::~AutonomousGroup()
{
	delete m_cAutonRollers;
	delete m_cAutonLifter;

}

// Called just before this Command runs the first time
void AutonomousGroup::Initialize()
{


}

// Called repeatedly when this Command is scheduled to run
void AutonomousGroup::Execute()
{

}

// Make this return true when this Command no longer needs to run execute()
bool AutonomousGroup::IsFinished()
{
return false;
}

// Called once after isFinished returns true
void AutonomousGroup::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonomousGroup::Interrupted()
{
	End();
}
