#include "AutonomousGroup.h"

AutonomousGroup::AutonomousGroup()
{
	m_cAutonRollers1 = new ControlRollers();
	m_cAutonRollers2 = new ControlRollers();
	m_cAutonRollers3 = new ControlRollers();
	m_cAutonRollers4 = new ControlRollers();
	m_cAutonLifter1 = new ControlLifter();
	m_cAutonLifter2 = new ControlLifter();
	m_cAutonLifter3 = new ControlLifter();
	m_cAutonDrive1 = new AutonDriveStraight();
	m_cAutonDrive2 = new AutonDriveStraight();
	m_cAutonDrive3 = new AutonDriveStraight();
	m_cAutonDrive4 = new AutonDriveStraight();
	m_cAutonDrive5 = new AutonDriveStraight();
	AddSequential(m_cAutonDrive1);
	AddSequential(m_cAutonRollers1);
	AddParallel(m_cAutonLifter1);
	AddSequential(m_cAutonDrive2);
	AddSequential(m_cAutonRollers2);
	AddParallel(m_cAutonLifter2);
	AddSequential(m_cAutonDrive3);
	AddSequential(m_cAutonRollers3);
	AddParallel(m_cAutonLifter3);
	AddSequential(m_cAutonDrive4);
	AddSequential(m_cAutonDrive5);
	AddSequential(m_cAutonRollers4);
}

AutonomousGroup::~AutonomousGroup()
{
	delete m_cAutonDrive1;
	delete m_cAutonDrive2;
	delete m_cAutonDrive3;
	delete m_cAutonDrive4;
	delete m_cAutonDrive5;
	delete m_cAutonLifter1;
	delete m_cAutonLifter2;
	delete m_cAutonLifter3;
	delete m_cAutonRollers1;
	delete m_cAutonRollers2;
	delete m_cAutonRollers3;
	delete m_cAutonRollers4;
}

// Called just before this Command runs the first time
void AutonomousGroup::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void AutonomousGroup::Execute()
{
	// Will change values once robot speed and positioning is known.
	m_cAutonDrive1->m_nDrivePowerL=1,m_cAutonDrive1->m_nDrivePowerR=1;
	m_cAutonDrive1->UpdateTimer(20),m_cAutonDrive1->gyroMode=true;
	m_cAutonDrive1->m_bExecute=true;
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
