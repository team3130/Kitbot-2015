#include "AutonomousGroup.h"

AutonomousGroup::AutonomousGroup()
{
	//Goal: pick up a bin, place it on yellow tote, pick stack up, and move into auton zone
	m_cAutonPusher1 = new AutonPusher();
	m_cAutonPusher2 = new AutonPusher();
	m_cAutonLifter1 = new AutonLifter();
	m_cAutonLifter2 = new AutonLifter();
	m_cAutonLifter3 = new AutonLifter();
	m_cAutonDriveStraight1 = new AutonDriveStraight();
	m_cAutonDriveStraight2 = new AutonDriveStraight();
	m_cAutonRollers1 = new AutonRollers();
	m_cAutonTurn1 = new AutonTurn();
	
	AddSequential(m_cAutonPusher1);			//extend pusher a little for bin
	AddSequential(m_cAutonLifter1);			//lifts bin up
	AddSequential(m_cAutonPusher2);			//grabs bin back
	AddParallel(m_cAutonRollers1);			//While intaking tote
	//AddSequential(m_cAutonDriveStraight1);	//Drive forward a bit to intake
	AddSequential(m_cAutonLifter2);			//sets the bin down onto the yellow tote
	AddSequential(m_cAutonLifter3);			//Pick up the whole bin-tote stack
	//AddSequential(m_cAutonTurn1);			//Turns robot towards Auton Zone
	//AddSequential(m_cAutonDriveStraight2);	//Robot drives into Auton Zone
}

AutonomousGroup::~AutonomousGroup()
{
	delete m_cAutonLifter1;
	delete m_cAutonLifter2;
	delete m_cAutonLifter3;
	delete m_cAutonPusher1;
	delete m_cAutonPusher2;
	delete m_cAutonDriveStraight1;
	delete m_cAutonDriveStraight2;
	delete m_cAutonRollers1;
	delete m_cAutonTurn1;
}

// Called just before this Command runs the first time
void AutonomousGroup::Initialize()
{
	// Will change values once robot speed and positioning is known.
		//Rollers
	m_cAutonRollers1->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton1-Intake-Time", 3), 1, -1);

		//Pusher
	m_cAutonPusher1->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton1-Pusher-Out-Time",3), 1);
	m_cAutonPusher2->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton1-Pusher-In-Time",5), -1);

		//Lifter
	m_cAutonLifter1->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton1-Lifter1-Time",5),
			Preferences::GetInstance()->GetDouble("Auton1-Lifter1-Threshold",15),
			Preferences::GetInstance()->GetDouble("Auton1-Lifter1-Goal",1600));
	m_cAutonLifter2->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton1-Lifter2-Time",5),
			Preferences::GetInstance()->GetDouble("Auton1-Lifter2-Threshold",15),
			Preferences::GetInstance()->GetDouble("Auton1-Lifter2-Goal",0));
	m_cAutonLifter3->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton1-Lifter3-Time",7),
			Preferences::GetInstance()->GetDouble("Auton1-Lifter3-Threshold",15),
			Preferences::GetInstance()->GetDouble("Auton1-Lifter3-Goal",400));

		//Driving
	m_cAutonDriveStraight1->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton1-Distance-Tote",20),
			Preferences::GetInstance()->GetDouble("Auton1-Tolerance-Tote",2.5),
			Preferences::GetInstance()->GetDouble("Auton1-Speed-Tote",0.65),
			Preferences::GetInstance()->GetDouble("Auton1-Timeout-Tote",3));
	m_cAutonDriveStraight2->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton1-Distance-Zone",160),
			Preferences::GetInstance()->GetDouble("Auton1-Tolerance-Zone",5.5),
			Preferences::GetInstance()->GetDouble("Auton1-Speed-Zone",0.65),
			Preferences::GetInstance()->GetDouble("Auton1-Timeout-Zone",7));

		//Turning
	m_cAutonTurn1->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton1-Turn1-Angle",40),
			Preferences::GetInstance()->GetDouble("Auton1-Turn1-Threshold",2.5), 3);
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
