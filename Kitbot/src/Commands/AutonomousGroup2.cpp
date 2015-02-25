#include "AutonomousGroup2.h"

AutonomousGroup2::AutonomousGroup2()
{
	//Goal: Pick up both bins on step with moose, drive back while setting them down
	//Antlers move up, and fit in the auton zone somehow, either by turning or activating arms.
	m_cAntlerMoose1 = new AutonAntlerMoose();
	m_cMooseLifter1 = new AutonMooseLifter();
	m_cMooseLifter2 = new AutonMooseLifter();
	m_cAutonDrive1 = new AutonDriveStraight();
	m_cAutonDrive2 = new AutonDriveStraight();
	m_cAutonDrive3 = new AutonDriveStraight();
	m_cAutonDumb1 = new AutonDumbDrive();
	m_cAutonTurner = new AutonTurn();
	m_cAutonIntakeArms = new AutonIntakeArms();
	
	AddSequential(m_cAutonDrive1);		//Drive backwards
	AddSequential(m_cAutonDumb1);		//Creep backwards slowly to ensure level with step
	AddSequential(m_cMooseLifter1);		//Lift up both middle bins with moose
	AddParallel(m_cMooseLifter2);		//While the moose is lowering, setting the bins down
	AddSequential(m_cAutonDrive2);		//Drive forwards to the auton zone
	AddSequential(m_cAntlerMoose1);		//Retract antlers up
	AddSequential(m_cAutonDrive3);		//Drive back a bit into the auton zone
	AddSequential(m_cAutonIntakeArms);	//Extend intake arms to fit in auton zone
	//AddSequential(m_cAutonTurner);	//Turn to fit in auton zone
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
	m_cAutonDrive1->SetGoal(
			Preferences::GetInstance()->GetDouble("Auto-Distance-Step",-54),
			Preferences::GetInstance()->GetDouble("Auto-Tolerance-Step",1.5),
			Preferences::GetInstance()->GetDouble("Auto-Speed-Step",0.75),
			Preferences::GetInstance()->GetDouble("Auto-Timeout-Step",4) );
	m_cAutonDrive2->SetGoal(
			Preferences::GetInstance()->GetDouble("Auto-Distance-Zone",160),
			Preferences::GetInstance()->GetDouble("Auto-Tolerance-Zone",5.5),
			Preferences::GetInstance()->GetDouble("Auto-Speed-Zone",0.65),
			Preferences::GetInstance()->GetDouble("Auto-Timeout-Zone",7) );
	m_cAutonDrive3->SetGoal(
			Preferences::GetInstance()->GetDouble("Auto-Distance-Self",-40),
			Preferences::GetInstance()->GetDouble("Auto-Tolerance-Self",1.5),
			Preferences::GetInstance()->GetDouble("Auto-Speed-Self",0.75),
			Preferences::GetInstance()->GetDouble("Auto-Timeout-Self",4) );

		//Dumb Drive
	m_cAutonDumb1->SetGoal(
			Preferences::GetInstance()->GetDouble("Auto-Dumb-Speed", -0.55),
			Preferences::GetInstance()->GetDouble("Auto-Dumb-Time", 1.2));

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
	m_cAutonTurner->SetGoal(90, Preferences::GetInstance()->GetDouble("Auto-Turn-Threshold",2.5), 2);

		//Activate Intake Arms to fit within the Auto Zone
	m_cAutonIntakeArms->SetGoal(Preferences::GetInstance()->GetDouble("Auto-Intake-Arms-Time",15), true);

	CommandBase::antlerMoose->ControlLeftAntler(true);
	CommandBase::antlerMoose->ControlRightAntler(true);
	CommandBase::mooseLifter->MoveMooseLock(false);
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
