#include "AutonomousGroup6.h"

AutonomousGroup6::AutonomousGroup6()
{
	//Goal: pick up a bin
	m_cAutonPusher1 = new AutonPusher();
	m_cAutonLifter1 = new AutonLifter();
	m_cAutonLifter2 = new AutonLifter();
	m_cAutonLifter3 = new AutonLifter();
	m_cAutonLifter4 = new AutonLifter();
	m_cAutonBincher1 = new AutonBincher();
	m_cAutonBincher2 = new AutonBincher();
	m_cAutonDriveStraight1 = new AutonDriveStraight();
	m_cAutonTurn1 = new AutonDumbTurn();
	m_cAutonArms1 = new AutonIntakeArms();
	
	AddParallel(m_cAutonArms1);
	AddSequential(m_cAutonBincher1);		//opens bincher
	AddSequential(m_cAutonLifter4);			//lifts bin up
	AddSequential(m_cAutonPusher1);			//grabs bin back
	AddSequential(m_cAutonLifter1);			//lifts bin up
	AddSequential(m_cAutonBincher2);		//Binches bin
	AddSequential(m_cAutonLifter2);			//lowers lifter
	//AddSequential(m_cAutonLifter3);			//pushes bin up all the way in to bincher
	//AddSequential(m_cAutonTurn1);			//Turns robot towards Auton Zone
	//AddSequential(m_cAutonDriveStraight1);	//Robot drives into Auton Zone
}

AutonomousGroup6::~AutonomousGroup6()
{
	delete m_cAutonLifter1;
	delete m_cAutonLifter2;
	delete m_cAutonLifter3;
	delete m_cAutonLifter4;
	delete m_cAutonPusher1;
	delete m_cAutonDriveStraight1;
	delete m_cAutonTurn1;
	delete m_cAutonBincher1;
	delete m_cAutonBincher2;
	delete m_cAutonArms1;
}

// Called just before this Command runs the first time
void AutonomousGroup6::Initialize()
{
	// Will change values once robot speed and positioning is known.
		//Pusher
	m_cAutonPusher1->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton1-Pusher-Out-Time",3), -1);

		//Lifter
	m_cAutonLifter1->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton6-Lifter1-Time",5),
			Preferences::GetInstance()->GetDouble("Auton6-Lifter1-Threshold",15),
			Preferences::GetInstance()->GetDouble("Auton6-Lifter1-Goal",6385));
	m_cAutonLifter2->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton6-Lifter2-Time",4),
			Preferences::GetInstance()->GetDouble("Auton6-Lifter2-Threshold",15),
			Preferences::GetInstance()->GetDouble("Auton6-Lifter2-Goal",2000));
	m_cAutonLifter3->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton6-Lifter3-Time",4),
			Preferences::GetInstance()->GetDouble("Auton6-Lifter3-Threshold",15),
			Preferences::GetInstance()->GetDouble("Auton6-Lifter3-Goal",6385));
	m_cAutonLifter4->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton6-Lifter4-Time",2),
			Preferences::GetInstance()->GetDouble("Auton6-Lifter4-Threshold",15),
			Preferences::GetInstance()->GetDouble("Auton6-Lifter4-Goal",3000));


		//Driving
	m_cAutonDriveStraight1->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton6-Distance-Tote",146),
			Preferences::GetInstance()->GetDouble("Auton6-Tolerance-Tote",2.5),
			Preferences::GetInstance()->GetDouble("Auton6-Speed-Tote",-0.65),
			Preferences::GetInstance()->GetDouble("Auton6-Timeout-Tote",3));

		//Turning
	m_cAutonTurn1->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton6-Turn1-Turn",1),
			Preferences::GetInstance()->GetDouble("Auton1-Turn1-Timout",2.5));

		//Bincher
	m_cAutonBincher1->SetDir(
			Preferences::GetInstance()->GetBoolean("Auton6-Bincher-Direction",true));
	m_cAutonBincher2->SetDir(
			Preferences::GetInstance()->GetBoolean("Auton6-Bincher2-Direction",false));

		//Intake Arms
	m_cAutonArms1->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton6-Arms-Opentime",10),
			false);
}

// Called repeatedly when this Commsand is scheduled to run
void AutonomousGroup6::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool AutonomousGroup6::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void AutonomousGroup6::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonomousGroup6::Interrupted()
{
	End();
}
