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
	
	AddSequential(m_cAutonLifter1);			//moves lifter to bin-lifting height
	AddSequential(m_cAutonPusher1);			//moves lifter thing out to grab
	AddSequential(m_cAutonLifter2);			//lifts bin up
	AddSequential(m_cAutonPusher2);			//grabs bin back
	AddSequential(m_cAutonLifter3);			//sets the bin down onto the yellow tote
	AddSequential(m_cAutonIntakeArms1);		//Open the intake arms
	AddParallel(m_cAutonRollers1);			//While the rollers are intaking in
	AddParallel(m_cAutonIntakeArms2);		//And as the intake arms close in
	AddSequential(m_cAutonDriveStraight1);	//Drive forward to grab the yellow tote
	AddSequential(m_cAutonLifter4);			//Pick up the whole bin-tote stack
	AddSequential(m_cAutonTurn1);			//Turns robot towards Auton Zone
	AddSequential(m_cAutonDriveStraight2);	//Robot drives into Auton Zone
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
