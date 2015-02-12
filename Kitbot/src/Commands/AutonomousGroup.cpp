#include "AutonomousGroup.h"

AutonomousGroup::AutonomousGroup()
{
	m_cAutonRollers1 = new AutonRollers();
	m_cAutonRollers2 = new AutonRollers();
	m_cAutonRollers3 = new AutonRollers();
	m_cAutonRollers4 = new AutonRollers();
	m_cAutonOutput = new AutonPusher();
	m_cAutonLifter1 = new AutonLifter();
	m_cAutonLifter2 = new AutonLifter();
	m_cAutonLifter3 = new AutonLifter();
	m_cAutonLifter4 = new AutonLifter();
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
	AddSequential(m_cAutonLifter4);
	AddParallel(m_cAutonRollers4);
	AddSequential(m_cAutonOutput);
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
	delete m_cAutonLifter4;
	delete m_cAutonRollers1;
	delete m_cAutonRollers2;
	delete m_cAutonRollers3;
	delete m_cAutonRollers4;
	delete m_cAutonOutput;
}

// Called just before this Command runs the first time
void AutonomousGroup::Initialize()
{
	// Will change values once robot speed and positioning is known.
		//Drive
	m_cAutonDrive1->m_nDrivePowerL = 1,m_cAutonDrive1->m_nDrivePowerR = 1;
	m_cAutonDrive1->m_nEncoderStop = 20,m_cAutonDrive1->gyroMode = true;

	m_cAutonDrive2->m_nDrivePowerL = 1,m_cAutonDrive2->m_nDrivePowerR = 1;
	m_cAutonDrive2->m_nEncoderStop = 20,m_cAutonDrive2->gyroMode = true;

	m_cAutonDrive3->m_nDrivePowerL = 1,m_cAutonDrive3->m_nDrivePowerR = 1;
	m_cAutonDrive3->m_nEncoderStop = 20,m_cAutonDrive3->gyroMode = true;

	m_cAutonDrive4->m_nDrivePowerL = 1,m_cAutonDrive4->m_nDrivePowerR = -1;
	m_cAutonDrive4->m_nEncoderStop = 10,m_cAutonDrive4->gyroMode = false;

	m_cAutonDrive5->m_nDrivePowerL = 1,m_cAutonDrive5->m_nDrivePowerR = 1;
	m_cAutonDrive5->m_nEncoderStop = 20,m_cAutonDrive5->gyroMode = true;

		//Rollers
	m_cAutonRollers1->m_nLeftIntake = 1,m_cAutonRollers1->m_nRightIntake = 1;
	m_cAutonRollers1->m_nTimer = 20;

	m_cAutonRollers2->m_nLeftIntake = 1,m_cAutonRollers2->m_nRightIntake = 1;
	m_cAutonRollers2->m_nTimer = 20;

	m_cAutonRollers3->m_nLeftIntake = 1,m_cAutonRollers3->m_nRightIntake = 1;
	m_cAutonRollers3->m_nTimer = 20;

	m_cAutonRollers4->m_nLeftIntake = -1,m_cAutonRollers4->m_nRightIntake = -1;
	m_cAutonRollers4->m_nTimer = 20;

		//Output
	m_cAutonOutput->m_fDirection = 1;

		//Lifter
	m_cAutonLifter1->m_b2StageOn = true;

	m_cAutonLifter2->m_b2StageOn = true;

	m_cAutonLifter3->m_b2StageOn = true;

	m_cAutonLifter4->m_b2StageOn = false;
}

// Called repeatedly when this Command is scheduled to run
void AutonomousGroup::Execute()
{
	m_cAutonDrive1->m_bExecute = true;
	m_cAutonRollers1->m_bRollersExecute = true;
	m_cAutonLifter1->m_bLifterExecute = true;
	if(m_cAutonLifter1->lifter->GetLimitSwitchBot()){m_cAutonDrive2->m_bExecute = true;}
	m_cAutonRollers2->m_bRollersExecute = true;
	m_cAutonLifter2->m_bLifterExecute = true;
	if(m_cAutonLifter2->lifter->GetLimitSwitchBot()){m_cAutonDrive3->m_bExecute = true;}
	m_cAutonRollers3->m_bRollersExecute = true;
	m_cAutonLifter3->m_bLifterExecute = true;
	if(m_cAutonLifter3->lifter->GetLimitSwitchBot()){m_cAutonDrive4->m_bExecute = true;}
	m_cAutonDrive5->m_bExecute = true;
	m_cAutonLifter4->m_bLifterExecute = true;
	m_cAutonRollers4->m_bRollersExecute = true;
	m_cAutonOutput->m_bPusherExecute = true;
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
