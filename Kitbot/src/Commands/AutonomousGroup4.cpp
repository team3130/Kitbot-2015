#include "AutonomousGroup4.h"

AutonomousGroup4::AutonomousGroup4()
{
	//Goal: Pick up both bins on step with moose, drive back while setting them down
	//Antlers move up, and fit in the auton zone somehow, either by turning or activating arms.
	m_cMooseLifter1 = new AutonMooseLifter();
	m_cAutonDrive1 = new AutonDriveStraight();
	m_cAutonDrive2 = new AutonDriveStraight();
	m_cAutonDumb1 = new AutonDumbDrive();
	
	AddSequential(m_cAutonDrive1);		//Drive backwards
	AddSequential(m_cAutonDumb1);		//Creep backwards slowly to ensure level with step
	AddSequential(m_cMooseLifter1);		//Lift up both middle bins with moose
	AddSequential(m_cAutonDrive2);		//Drive forwards to the auton zone
}

AutonomousGroup4::~AutonomousGroup4()
{
	delete m_cAutonDrive1;
	delete m_cAutonDrive2;
	delete m_cAutonDumb1;
	delete m_cMooseLifter1;
}

// Called just before this Command runs the first time
void AutonomousGroup4::Initialize()
{
	// Will change values once robot speed and positioning is known.
		//Drive
	m_cAutonDrive1->SetGoal(
			-53,
			1.5,
			0.65,
			3);
	m_cAutonDrive2->SetGoal(
			60,
			1.5,
			0.65,
			7);

		//Dumb Drive
	m_cAutonDumb1->SetGoal(
			0.55,
			0.2);

		//Moose Lifter
	m_cMooseLifter1->SetGoal(0,
			1.0,
			true);

	CommandBase::antlerMoose->ControlLeftAntler(true);
	CommandBase::antlerMoose->ControlRightAntler(true);
	CommandBase::mooseLifter->MoveMooseLock(false);
}

// Called repeatedly when this Command is scheduled to run
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
