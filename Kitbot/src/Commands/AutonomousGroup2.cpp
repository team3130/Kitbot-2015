#include "AutonomousGroup2.h"

AutonomousGroup2::AutonomousGroup2()
{
	m_cAntlerMoose1 = new AutonAntlerMoose();
	m_cMooseLifter1 = new AutonMooseLifter();
	m_cMooseLifter2 = new AutonMooseLifter();
	m_cAutonDrive1 = new AutonDriveStraight();
	m_cAutonDrive2 = new AutonDriveStraight();
	m_cAutonDrive3 = new AutonDriveStraight();
	m_cAutonDumb1 = new AutonDumbDrive();
	m_cAutonTurner = new AutonTurn();
	m_cAutonIntakeArms = new AutonIntakeArms();
	AddSequential(m_cAutonDrive1);
	AddSequential(m_cAutonDumb1);
	AddSequential(m_cMooseLifter1);
	AddParallel(m_cMooseLifter2);
	AddSequential(m_cAutonDrive2);
	AddSequential(m_cAntlerMoose1);
	AddSequential(m_cAutonDrive3);
	AddSequential(m_cAutonIntakeArms);
	//AddSequential(m_cAutonTurner);
}

AutonomousGroup2::~AutonomousGroup2()
{
	delete m_cAutonDrive1;
	delete m_cAutonDrive2;
	delete m_cAutonDrive3;
	delete m_cAutonDumb1;
	delete m_cAntlerMoose1;
	delete m_cMooseLifter1;
	delete m_cMooseLifter2;
	delete m_cAutonIntakeArms;
	delete m_cAutonTurner;
}

// Called just before this Command runs the first time
void AutonomousGroup2::Initialize()
{
	// Will change values once robot speed and positioning is known.
		//Drive
	m_cAutonDrive1->SetGoal(Preferences::GetInstance()->GetDouble("Auto-Distance-Step",-54), 1.5, 0.75);
	m_cAutonDrive2->SetGoal(Preferences::GetInstance()->GetDouble("Auto-Distance-Zone",160), 5.5, 0.65);
	m_cAutonDrive3->SetGoal(Preferences::GetInstance()->GetDouble("Auto-Distance-Self",-40), 1.5, 0.75);

		//Dumb Drive
	m_cAutonDumb1->SetGoal(Preferences::GetInstance()->GetDouble("Auto-Dumb-Time", 0.8));

		//Moose Lifter
	m_cMooseLifter1->SetGoal(0,
			Preferences::GetInstance()->GetDouble("Auto-MooseUp-Time", 1.0),
			true);
	m_cMooseLifter2->SetGoal(
			Preferences::GetInstance()->GetDouble("Auto-MooseDrop",140),
			Preferences::GetInstance()->GetDouble("Auto-MooseDown-Time", 2.0),
			false);

		//Antler
	m_cAntlerMoose1->SetGoal(Preferences::GetInstance()->GetDouble("Auto-Antlers-Time",1.5));

		//Turn to fit within the Auto Zone
	m_cAutonTurner->SetGoal(90, 2);

		//Activate Intake Arms to fit within the Auto Zone
	m_cAutonIntakeArms->SetGoal(Preferences::GetInstance()->GetDouble("Auto-Intake-Arms-Time",15));

	CommandBase::antlerMoose->ControlLeftAntler(DoubleSolenoid::kForward);
	CommandBase::antlerMoose->ControlRightAntler(DoubleSolenoid::kForward);
}

// Called repeatedly when this Command is scheduled to run
void AutonomousGroup2::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool AutonomousGroup2::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void AutonomousGroup2::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonomousGroup2::Interrupted()
{
	End();
}
