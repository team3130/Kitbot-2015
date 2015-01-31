#include "AutonomousGroup2.h"

AutonomousGroup::AutonomousGroup()
{
	m_cAntlerMoose1 = new AutonAntlerMoose();
	m_cMooseLifter1 = new AutonMooseLifter();
	m_cMooseLifter2 = new AutonMooseLifter();
	m_cAutonDrive1 = new AutonDriveStraight();
	m_cAutonDrive2 = new AutonDriveStraight();
}

AutonomousGroup::~AutonomousGroup()
{
	delete m_cAutonDrive1;
	delete m_cAutonDrive2;
	delete m_cAntlerMoose1;
	delete m_cMooseLifter1;
	delete m_cMooseLifter2;
}

// Called just before this Command runs the first time
void AutonomousGroup::Initialize()
{
	// Will change values once robot speed and positioning is known.
		//Drive
	m_cAutonDrive1->m_nDrivePowerL = 1,m_cAutonDrive1->m_nDrivePowerR = 1;
	m_cAutonDrive1->m_nTimer = 20,m_cAutonDrive1->gyroMode = true;

	m_cAutonDrive2->m_nDrivePowerL = 1,m_cAutonDrive2->m_nDrivePowerR = 1;
	m_cAutonDrive2->m_nTimer = 20,m_cAutonDrive2->gyroMode = true;

		//Moose Lifter
	m_cMooseLifter1->m_bMooseOn = true;

	m_cMooseLifter2->m_bMooseOn = false;

		//Antler
	m_cAntlerMoose1->m_bLockDisabled = true;
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
