#include "AutonomousGroup5.h"

AutonomousGroup5::AutonomousGroup5()
{

}

AutonomousGroup5::~AutonomousGroup5()
{
}

// Called just before this Command runs the first time
void AutonomousGroup5::Initialize()
{
/*	// Will change values once robot speed and positioning is known.
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
*/
}

// Called repeatedly when this Command is scheduled to run
void AutonomousGroup5::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool AutonomousGroup5::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void AutonomousGroup5::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonomousGroup5::Interrupted()
{
	End();
}
