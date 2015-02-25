#include "AutonomousGroup.h"

AutonomousGroup::AutonomousGroup()
{
	//Goal: pick up a yellow tote and move into auton zone
	m_cAutonLifter1 = new AutonLifter();
	m_cAutonDriveStraight1 = new AutonDriveStraight();
	m_cAutonTurn1 = new AutonTurn();
	
	AddSequential(m_cAutonLifter1);			//lifts tote up
	//AddSequential(m_cAutonTurn1);			//Turns robot towards Auton Zone
	//AddSequential(m_cAutonDriveStraight1);	//Robot drives into Auton Zone
}

AutonomousGroup::~AutonomousGroup()
{
	delete m_cAutonLifter1;
	delete m_cAutonDriveStraight1;
	delete m_cAutonTurn1;
}

// Called just before this Command runs the first time
void AutonomousGroup::Initialize()
{
	// Will change values once robot speed and positioning is known.
		//Lifter
	m_cAutonLifter1->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton1-Lifter1-Time",5),
			Preferences::GetInstance()->GetDouble("Auton1-Lifter1-Threshold",15),
			Preferences::GetInstance()->GetDouble("Auton1-Lifter1-Goal",1000));

		//Driving
	m_cAutonDriveStraight1->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton1-Distance-Tote",40),
			Preferences::GetInstance()->GetDouble("Auton1-Tolerance-Tote",2.5),
			Preferences::GetInstance()->GetDouble("Auton1-Speed-Tote",0.65),
			Preferences::GetInstance()->GetDouble("Auton1-Timeout-Tote",3));

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
