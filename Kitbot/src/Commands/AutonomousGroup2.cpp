#include "AutonomousGroup2.h"

AutonomousGroup2::AutonomousGroup2()
{
	m_cAntlerMoose1 = new AutonAntlerMoose();
	m_cMooseLifter1 = new AutonMooseLifter();
	m_cMooseLifter2 = new AutonMooseLifter();
	m_cAutonDrive1 = new AutonDriveStraight();
	m_cAutonDrive2 = new AutonDriveStraight();
	AddSequential(m_cAutonDrive1);
	AddSequential(m_cMooseLifter1);
	AddSequential(m_cAutonDrive2);
	AddSequential(m_cMooseLifter2);
	AddSequential(m_cAntlerMoose1);
}

AutonomousGroup2::~AutonomousGroup2()
{
	delete m_cAutonDrive1;
	delete m_cAutonDrive2;
	delete m_cAntlerMoose1;
	delete m_cMooseLifter1;
	delete m_cMooseLifter2;
}

// Called just before this Command runs the first time
void AutonomousGroup2::Initialize()
{
	// Will change values once robot speed and positioning is known.
		//Drive
	m_cAutonDrive1->speed = 1, m_cAutonDrive1->SetGoal()

	m_cAutonDrive2->m_nDrivePowerL = -0.3,m_cAutonDrive2->m_nDrivePowerR = -0.3;
	m_cAutonDrive2->m_nEncoderStop = 1,m_cAutonDrive2->gyroMode = true;

		//Moose Lifter
	m_cMooseLifter1->m_bMooseOn = true;

	m_cMooseLifter2->m_bMooseOn = false;

		//Antler
	m_cAntlerMoose1->m_bLockDisabled = true;
}

// Called repeatedly when this Command is scheduled to run
void AutonomousGroup2::Execute()
{
	m_cAutonDrive1->m_bExecute = true;
	m_cMooseLifter1->m_bMooseExecute = true;
	m_cAutonDrive2->m_bExecute = true;
	m_cMooseLifter2->m_bMooseExecute = true;
	m_cAntlerMoose1->m_bAntlerMooseExecute = true;
}

// Make this return true when this Command no longer needs to run execute()
bool AutonomousGroup2::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void AutonomousGroup2::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonomousGroup2::Interrupted()
{
	End();
}
