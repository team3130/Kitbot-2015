#include "AutonomousGroup.h"

AutonomousGroup::AutonomousGroup()
{
	//Goal: pick up a bin, place it on yellow tote, pick stack up, and move into auton zone
	m_cAutonRollers1 = new AutonRollers();
	m_cAutonRollers2 = new AutonRollers();
	m_cAutonPusher1 = new AutonPusher();
	m_cAutonPusher2 = new AutonPusher();
	m_cAutonLifter1 = new AutonLifter();
	m_cAutonLifter2 = new AutonLifter();
	m_cAutonLifter3 = new AutonLifter();
	m_cAutonLifter4 = new AutonLifter();
	m_cAutonIntakeArms1 = new AutonIntakeArms();
	m_cAutonIntakeArms2 = new AutonIntakeArms();
	m_cAutonDriveStraight1 = new AutonDriveStraight();
	m_cAutonDriveStraight2 = new AutonDriveStraight();
	m_cAutonTurn1 = new AutonTurn();
}

AutonomousGroup::~AutonomousGroup()
{
	delete m_cAutonLifter1;
	delete m_cAutonLifter2;
	delete m_cAutonLifter3;
	delete m_cAutonLifter4;
	delete m_cAutonRollers1;
	delete m_cAutonRollers2;
	delete m_cAutonPusher1;
	delete m_cAutonPusher2;
	delete m_cAutonDriveStraight1;
	delete m_cAutonDriveStraight2;
	delete m_cAutonIntakeArms1;
	delete m_cAutonIntakeArms2;
	delete m_cAutonTurn1;
}

// Called just before this Command runs the first time
void AutonomousGroup::Initialize()
{
	// Will change values once robot speed and positioning is known.
		//Rollers

		//Pusher

		//Lifter

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
