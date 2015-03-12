#include "AutonomousGroup8.h"

AutonomousGroup8::AutonomousGroup8()
{
	//Goal: pick up a bin
	m_cAutonPusher1 = new AutonPusher();
	m_cAutonLifter1 = new AutonLifter();
	m_cAutonLifter2 = new AutonLifter();
	m_cAutonLifter3 = new AutonLifter();
	m_cAutonLifter4 = new AutonLifter();
	m_cAutonLifter5 = new AutonLifter();
	m_cAutonBincher1 = new AutonBincher();
	m_cAutonBincher2 = new AutonBincher();
	m_cAutonDriveStraight1 = new AutonDriveStraight();
	m_cAutonDriveStraight4 = new AutonDriveStraight();
	m_cAutonTurn1 = new AutonDumbTurn();
	m_cAutonArms1 = new AutonIntakeArms();
	m_cAutonArms2 = new AutonIntakeArms();
	m_cAutonRollers1 = new AutonRollers();
	m_cAutonRollers2 = new AutonRollers();
	
	AddParallel(m_cAutonArms1);				//opens arms
	AddSequential(m_cAutonBincher1);		//opens bincher
	AddSequential(m_cAutonLifter4);			//lifts bin up
	AddSequential(m_cAutonPusher1);			//grabs bin back
	AddSequential(m_cAutonLifter1);			//lifts bin up
	AddSequential(m_cAutonBincher2);		//Binches bin
	AddSequential(m_cAutonLifter2);			//lowers lifter

	AddSequential(m_cAutonDriveStraight1);
	AddParallel(m_cAutonRollers1);
	AddSequential(m_cAutonArms2);
	AddSequential(m_cAutonLifter5);
	AddParallel(m_cAutonLifter3);
	AddParallel(m_cAutonRollers2);

	//AddSequential(m_cAutonTurn1);
	//AddSequential(m_cAutonDriveStraight4);


}

AutonomousGroup8::~AutonomousGroup8()
{
	delete m_cAutonLifter1;
	delete m_cAutonLifter2;
	delete m_cAutonLifter3;
	delete m_cAutonLifter4;
	delete m_cAutonLifter5;
	delete m_cAutonPusher1;
	delete m_cAutonDriveStraight1;
	delete m_cAutonDriveStraight4;
	delete m_cAutonTurn1;
	delete m_cAutonBincher1;
	delete m_cAutonBincher2;
	delete m_cAutonArms1;
	delete m_cAutonArms2;
	delete m_cAutonRollers1;
	delete m_cAutonRollers2;
}

// Called just before this Command runs the first time
void AutonomousGroup8::Initialize()
{
	// Will change values once robot speed and positioning is known.
		//Pusher
	m_cAutonPusher1->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton1-Pusher-Out-Time",2), -1);

		//Lifter
	m_cAutonLifter1->SetGoal(	//second
			Preferences::GetInstance()->GetDouble("Auton8-Lifter1-Time",2),
			Preferences::GetInstance()->GetDouble("Auton8-Lifter1-Threshold",15),
			Preferences::GetInstance()->GetDouble("Auton8-Lifter1-Goal",6385));
	m_cAutonLifter2->SetGoal(	//third
			Preferences::GetInstance()->GetDouble("Auton8-Lifter2-Time",2),
			Preferences::GetInstance()->GetDouble("Auton8-Lifter2-Threshold",15),
			Preferences::GetInstance()->GetDouble("Auton8-Lifter2-Goal",2000));
	m_cAutonLifter3->SetGoal(	//fifth
			Preferences::GetInstance()->GetDouble("Auton8-Lifter3-Time",2),
			Preferences::GetInstance()->GetDouble("Auton8-Lifter3-Threshold",15),
			Preferences::GetInstance()->GetDouble("Auton8-Lifter3-Goal",3000));
	m_cAutonLifter4->SetGoal(	//first
			Preferences::GetInstance()->GetDouble("Auton8-Lifter4-Time",2),
			Preferences::GetInstance()->GetDouble("Auton8-Lifter4-Threshold",15),
			Preferences::GetInstance()->GetDouble("Auton8-Lifter4-Goal",3000));
	m_cAutonLifter5->SetGoal(	//fourth
			Preferences::GetInstance()->GetDouble("Auton8-Lifter5-Time",2),
			Preferences::GetInstance()->GetDouble("Auton8-Lifter5-Threshold",15),
			Preferences::GetInstance()->GetDouble("Auton8-Lifter5-Goal",500));


		//Driving
	m_cAutonDriveStraight4->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton8-Distance-Tote4",146),
			Preferences::GetInstance()->GetDouble("Auton8-Tolerance-Tote4",2.5),
			Preferences::GetInstance()->GetDouble("Auton8-Speed-Tote4",-0.65),
			Preferences::GetInstance()->GetDouble("Auton8-Timeout-Tote4",3));
	m_cAutonDriveStraight1->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton8-Distance-Tote1",22.25),
			Preferences::GetInstance()->GetDouble("Auton8-Tolerance-Tote1",2.5),
			Preferences::GetInstance()->GetDouble("Auton8-Speed-Tote1",.65),
			Preferences::GetInstance()->GetDouble("Auton8-Timeout-Tote1",3));

		//Turning - Unfinished
	m_cAutonTurn1->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton8-Turn1-Turn",1),
			Preferences::GetInstance()->GetDouble("Auton1-Turn1-Timout",2.5));

		//Bincher
	m_cAutonBincher1->SetDir(
			Preferences::GetInstance()->GetBoolean("Auton8-Bincher-Direction",true));
	m_cAutonBincher2->SetDir(
			Preferences::GetInstance()->GetBoolean("Auton8-Bincher2-Direction",false));

		//Intake Arms
	m_cAutonArms1->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton8-Arms-Opentime",10),
			false);
	m_cAutonArms2->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton8-Arms2-Opentime",2),
			true);

		//Rollers
	m_cAutonRollers1->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton8-Rollers1-Runtime",2),
			1,
			-1);
	m_cAutonRollers2->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton8-Rollers2-Runtime",2),
			-1,
			-1);
}

// Called repeatedly when this Commsand is scheduled to run
void AutonomousGroup8::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool AutonomousGroup8::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void AutonomousGroup8::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonomousGroup8::Interrupted()
{
	End();
}
