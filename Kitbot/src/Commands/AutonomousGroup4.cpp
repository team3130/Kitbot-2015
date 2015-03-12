#include "AutonomousGroup4.h"

AutonomousGroup4::AutonomousGroup4()
{
	//Goal: pick up a bin
	m_cAutonPusher1 = new AutonPusher();
	m_cAutonPusher2 = new AutonPusher();
	m_cAutonLifter1 = new AutonLifter();
	m_cAutonDriveStraight1 = new AutonDriveStraight();
	m_cAutonTurn1 = new AutonTurn();
	
	AddSequential(m_cAutonPusher1);			//extend pusher a little for bin
	AddSequential(m_cAutonLifter1);			//lifts bin up
	AddSequential(m_cAutonPusher2);			//grabs bin back
	//AddSequential(m_cAutonTurn1);			//Turns robot towards Auton Zone
	//AddSequential(m_cAutonDriveStraight1);	//Robot drives into Auton Zone
}

AutonomousGroup4::~AutonomousGroup4()
{
	delete m_cAutonLifter1;
	delete m_cAutonPusher1;
	delete m_cAutonPusher2;
	delete m_cAutonDriveStraight1;
	delete m_cAutonTurn1;
}

// Called just before this Command runs the first time
void AutonomousGroup4::Initialize()
{
	// Will change values once robot speed and positioning is known.
		//Pusher
	m_cAutonPusher1->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton1-Pusher-Out-Time",3), 1);
	m_cAutonPusher2->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton1-Pusher-In-Time",5), -1);

		//Lifter
	m_cAutonLifter1->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton1-Lifter1-Time",5),
			Preferences::GetInstance()->GetDouble("Auton1-Lifter1-Threshold",15),
			Preferences::GetInstance()->GetDouble("Auton1-Lifter1-Goal",2000));

		//Driving
	m_cAutonDriveStraight1->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton1-Distance-Tote",20),
			Preferences::GetInstance()->GetDouble("Auton1-Tolerance-Tote",2.5),
			Preferences::GetInstance()->GetDouble("Auton1-Speed-Tote",0.65),
			Preferences::GetInstance()->GetDouble("Auton1-Timeout-Tote",3));

		//Turning
	m_cAutonTurn1->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton1-Turn1-Angle",40),
			Preferences::GetInstance()->GetDouble("Auton1-Turn1-Threshold",2.5), 3);

}

// Called repeatedly when this Commsand is scheduled to run
void AutonomousGroup4::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool AutonomousGroup4::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void AutonomousGroup4::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonomousGroup4::Interrupted()
{
	End();
}
