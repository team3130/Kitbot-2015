#include "AutonomousGroup3.h"

AutonomousGroup3::AutonomousGroup3()
{
	//Goal: Drive Forward into the auton zone and fit somehow
	m_cAutonDriveStraight1 = new AutonDriveStraight();
	
	AddSequential(m_cAutonDriveStraight1);	//Robot drives into Auton Zone
}

AutonomousGroup3::~AutonomousGroup3()
{
	delete m_cAutonDriveStraight1;
}

// Called just before this Command runs the first time
void AutonomousGroup3::Initialize()
{
	// Will change values once robot speed and positioning is known.
		//Driving
	m_cAutonDriveStraight1->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton3-Distance-Zone",78),
			Preferences::GetInstance()->GetDouble("Auton3-Threshold-Zone",1.5),
			Preferences::GetInstance()->GetDouble("Auton3-Speed-Zone",-0.40),
			Preferences::GetInstance()->GetDouble("Auton3-Timeout-Zone",3));
}

// Called repeatedly when this Command is scheduled to run
void AutonomousGroup3::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool AutonomousGroup3::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void AutonomousGroup3::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonomousGroup3::Interrupted()
{
	End();
}
