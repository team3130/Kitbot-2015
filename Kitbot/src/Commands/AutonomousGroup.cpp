#include "AutonomousGroup.h"

AutonomousGroup::AutonomousGroup()
{
	//Goal: pick up a bin, place it on yellow tote, pick stack up, and move into auton zone
	m_cAutonPusher1 = new AutonPusher();
	m_cAutonLifter1 = new AutonLifter();
	m_cAutonLifter2 = new AutonLifter();
	m_cAutonLifter3 = new AutonLifter();
	m_cAutonDriveStraight1 = new AutonDriveStraight();
	m_cAutonTurn1 = new AutonTurn();
	
	AddSequential(m_cAutonLifter1);			//lifts bin up
	AddSequential(m_cAutonPusher1);			//grabs bin back
	AddSequential(m_cAutonLifter2);			//sets the bin down onto the yellow tote
	AddSequential(m_cAutonLifter3);			//Pick up the whole bin-tote stack
	//AddSequential(m_cAutonTurn1);			//Turns robot towards Auton Zone
	//AddSequential(m_cAutonDriveStraight1);	//Robot drives into Auton Zone
}

AutonomousGroup::~AutonomousGroup()
{
	delete m_cAutonLifter1;
	delete m_cAutonLifter2;
	delete m_cAutonLifter3;
	delete m_cAutonPusher1;
	delete m_cAutonDriveStraight1;
	delete m_cAutonTurn1;
}

// Called just before this Command runs the first time
void AutonomousGroup::Initialize()
{
	// Will change values once robot speed and positioning is known.
		//Pusher
	m_cAutonPusher1->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton1-Pusher-In-Time",5), 3);

		//Lifter
	m_cAutonLifter1->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton1-Lifter1-Time",3),
			Preferences::GetInstance()->GetDouble("Auton1-Lifter1-Threshold",15),
			Preferences::GetInstance()->GetDouble("Auton1-Lifter1-Goal",1600));
	m_cAutonLifter2->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton1-Lifter2-Time",3),
			Preferences::GetInstance()->GetDouble("Auton1-Lifter2-Threshold",15),
			Preferences::GetInstance()->GetDouble("Auton1-Lifter2-Goal",0));
	m_cAutonLifter3->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton1-Lifter3-Time",5),
			Preferences::GetInstance()->GetDouble("Auton1-Lifter3-Threshold",15),
			Preferences::GetInstance()->GetDouble("Auton1-Lifter3-Goal",400));

		//Driving
	m_cAutonDriveStraight1->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton1-Distance-Zone",160),
			Preferences::GetInstance()->GetDouble("Auton1-Tolerance-Zone",5.5),
			Preferences::GetInstance()->GetDouble("Auton1-Speed-Zone",0.65),
			Preferences::GetInstance()->GetDouble("Auton1-Timeout-Zone",7));

		//Turning
	m_cAutonTurn1->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton1-Turn1-Angle",90),
			Preferences::GetInstance()->GetDouble("Auton1-Turn1-Time",2));
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
