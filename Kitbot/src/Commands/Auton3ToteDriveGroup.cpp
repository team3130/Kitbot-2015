#include "Auton3ToteDriveGroup.h"

Autonomous3ToteDriveGroup::Autonomous3ToteDriveGroup()
{
	m_cAutonDriveStraight1 = new AutonDriveStraight();
	m_cAutonDriveStraight2 = new AutonDriveStraight();
	m_cAutonDriveStraight3 = new AutonDriveStraight();
	m_cAutonRollers1 = new AutonRollers();
	m_cAutonRollers2 = new AutonRollers();
	m_cAutonArms1 = new AutonIntakeArms();
	m_cAutonArms2 = new AutonIntakeArms();
	m_cAutonLifter1 = new AutonLifter();
	m_cAutonLifter2 = new AutonLifter();

	AddSequential(m_cAutonDriveStraight1);
	AddParallel(m_cAutonRollers1);
	AddParallel(m_cAutonDriveStraight2);
	AddSequential(m_cAutonArms1);
	AddSequential(m_cAutonDriveStraight3);
	AddParallel(m_cAutonArms2);
	AddSequential(m_cAutonRollers2);
	AddSequential(m_cAutonLifter1);
	AddParallel(m_cAutonLifter2);
}

Autonomous3ToteDriveGroup::~Autonomous3ToteDriveGroup()
{
	delete m_cAutonDriveStraight1;
	delete m_cAutonDriveStraight2;
	delete m_cAutonDriveStraight3;
	delete m_cAutonArms1;
	delete m_cAutonArms2;
	delete m_cAutonLifter1;
	delete m_cAutonLifter2;
	delete m_cAutonRollers1;
	delete m_cAutonRollers2;
}

// Called just before this Command runs the first time
void Autonomous3ToteDriveGroup::Initialize()
{
	m_cAutonDriveStraight1->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton7-Distance-Tote3",40),
			Preferences::GetInstance()->GetDouble("Auton7-Tolerance-Tote3",.5),
			Preferences::GetInstance()->GetDouble("Auton7-Speed-Tote3",.65),
			Preferences::GetInstance()->GetDouble("Auton7-Timeout-Tote3",2)
			-10);
	m_cAutonDriveStraight2->SetGoal(
			30,
			.5,
			0.65,
			1);
	m_cAutonDriveStraight3->SetGoal(
			16,
			.5,
			0.65,
			1);

	m_cAutonRollers1->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton7-Rollers2-Runtime",2),
			-1,
			1);
	m_cAutonRollers2->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton7-Rollers3-Runtime",2),
			1,
			-1);

	m_cAutonArms1->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton7-Arms3-Opentime",1),
			false);
	m_cAutonArms2->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton7-Arms4-Opentime",1),
			true);

	m_cAutonLifter1->SetGoal(	//sixth
			Preferences::GetInstance()->GetDouble("Auton7-Lifter6-Time",2),
			Preferences::GetInstance()->GetDouble("Auton7-Lifter6-Threshold",15),
			Preferences::GetInstance()->GetDouble("Auton7-Lifter6-Goal",0));
	m_cAutonLifter2->SetGoal(	//seventh
			Preferences::GetInstance()->GetDouble("Auton7-Lifter7-Time",2),
			Preferences::GetInstance()->GetDouble("Auton7-Lifter7-Threshold",15),
			Preferences::GetInstance()->GetDouble("Auton7-Lifter7-Goal",3000));
}

// Called repeatedly when this Command is scheduled to run
void Autonomous3ToteDriveGroup::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool Autonomous3ToteDriveGroup::IsFinished()
{
	return m_cAutonLifter1->IsFinished();
}

// Called once after isFinished returns true
void Autonomous3ToteDriveGroup::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Autonomous3ToteDriveGroup::Interrupted()
{
	End();
}
