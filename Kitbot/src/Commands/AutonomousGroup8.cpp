#include "AutonomousGroup8.h"

AutonomousGroup8::AutonomousGroup8()
{
	//Goal: pick up a bin into bincher, then intake all yellow totes
	m_cAutonPusher1 = new AutonPusher();
	m_cAutonLifter1 = new AutonLifter();
	m_cAutonLifter2 = new AutonLifter();
	m_cAutonLifter3 = new AutonLifter();
	m_cAutonLifter4 = new AutonLifter();
	m_cAutonLifter5 = new AutonLifter();
	m_cAutonLifter6 = new AutonLifter();
	m_cAutonLifter7 = new AutonLifter();
	m_cAutonLifter8 = new AutonLifter();
	m_cAutonLifter9 = new AutonLifter();
	m_cAutonLifter10 = new AutonLifter();
	m_cAutonBincher1 = new AutonBincher();
	m_cAutonBincher2 = new AutonBincher();
	m_cAutonDriveStraight0 = new AutonDriveStraight();
	m_cAutonDriveStraight1 = new AutonDriveStraight();
	m_cAutonDriveStraight2 = new AutonDriveStraight();
	m_cAutonDriveStraight3 = new AutonDriveStraight();
	m_cAutonDriveStraight4 = new AutonDriveStraight();
	m_cAutonDriveStraight5 = new AutonDriveStraight();
	m_cAutonDriveStraight6 = new AutonDriveStraight();
	m_cAutonDriveStraight7 = new AutonDriveStraight();
	m_cAutonDriveStraight8 = new AutonDriveStraight();
	m_cAutonDriveStraight9 = new AutonDriveStraight();
	m_cAutonDriveTurn2 = new AutonSmartTurn();
	m_cAutonDriveTurn3 = new AutonSmartTurn();
	m_cAutonDriveIntake2 = new AutonDriveStraight();
	m_cAutonDriveIntake3 = new AutonDriveStraight();
	m_cAutonDriveAfterTurn2 = new AutonDriveStraight();
	m_cAutonDriveAfterTurn3 = new AutonDriveStraight();
	m_cAutonTurn1 = new AutonSmartTurn();
	m_cAutonTurn2 = new AutonSmartTurn();
	m_cAutonTurn3 = new AutonSmartTurn();
	m_cAutonArms1 = new AutonIntakeArms();
	m_cAutonArms2 = new AutonIntakeArms();
	m_cAutonArms3 = new AutonIntakeArms();
	m_cAutonArms4 = new AutonIntakeArms();
	m_cAutonArms5 = new AutonIntakeArms();
	m_cAutonArms6 = new AutonIntakeArms();
	m_cAutonRollers1 = new AutonRollers();
	m_cAutonRollers2 = new AutonRollers();
	m_cAutonRollers3 = new AutonRollers();
	m_cAutonRollers4 = new AutonRollers();
	m_cAutonRollers5 = new AutonRollers();
	m_cAutonRollers6 = new AutonRollers();
	m_cAutonDelay1 = new AutonDelay();
	m_cAutonDelay2 = new AutonDelay();
	
	AddParallel(m_cAutonArms1);				//opens arms
	AddSequential(m_cAutonBincher1);		//opens bincher
	AddSequential(m_cAutonLifter1);			//lifts bin up
	//AddSequential(m_cAutonPusher1);			//grabs bin back
	AddSequential(m_cAutonLifter2);			//lifts bin up
	AddSequential(m_cAutonBincher2);		//Binches bin
	AddSequential(m_cAutonLifter3);			//lowers lifter

	//AddSequential(m_cAutonDriveStraight0);
	AddSequential(m_cAutonTurn1);
	AddParallel(m_cAutonRollers1);
	AddSequential(m_cAutonDriveStraight1);	//Step forward to the tote
	AddSequential(m_cAutonArms2);			//Close arms
	AddSequential(m_cAutonTurn2);
	AddParallel(m_cAutonDriveStraight2);	//Go forward and suck the tote
	AddSequential(m_cAutonLifter4);
	AddSequential(m_cAutonDelay1);
	AddParallel(m_cAutonLifter5);

	AddSequential(m_cAutonDriveStraight3);
	AddParallel(m_cAutonRollers3);
	AddSequential(m_cAutonDriveTurn2);
	AddSequential(m_cAutonArms3);
	AddSequential(m_cAutonDriveIntake2);
	AddParallel(m_cAutonRollers4);
	AddSequential(m_cAutonArms4);
	AddSequential(m_cAutonDelay2);
	AddSequential(m_cAutonLifter6);
	AddSequential(m_cAutonDelay1);
	AddParallel(m_cAutonLifter7);
	AddSequential(m_cAutonDriveAfterTurn2);

	AddParallel(m_cAutonRollers5);
	AddSequential(m_cAutonDriveTurn3);
	AddSequential(m_cAutonArms5);
	AddSequential(m_cAutonDriveIntake3);
	AddParallel(m_cAutonRollers6);
	AddSequential(m_cAutonArms6);
	AddSequential(m_cAutonDelay2);
	AddSequential(m_cAutonLifter8);
	AddSequential(m_cAutonDelay1);
	AddSequential(m_cAutonLifter9);
	AddSequential(m_cAutonTurn3);
	AddSequential(m_cAutonDriveStraight4);
	AddSequential(m_cAutonLifter10);

	AddParallel(m_cAutonRollers2);
	AddParallel(m_cAutonDriveStraight7);

}

AutonomousGroup8::~AutonomousGroup8()
{
	delete m_cAutonLifter1;
	delete m_cAutonLifter2;
	delete m_cAutonLifter3;
	delete m_cAutonLifter4;
	delete m_cAutonLifter5;
	delete m_cAutonLifter6;
	delete m_cAutonLifter7;
	delete m_cAutonLifter8;
	delete m_cAutonLifter9;
	delete m_cAutonPusher1;
	delete m_cAutonDriveStraight0;
	delete m_cAutonDriveStraight1;
	delete m_cAutonDriveStraight2;
	delete m_cAutonDriveStraight3;
	delete m_cAutonDriveStraight4;
	delete m_cAutonDriveStraight5;
	delete m_cAutonDriveStraight6;
	delete m_cAutonDriveStraight7;
	delete m_cAutonDriveStraight8;
	delete m_cAutonDriveStraight9;
	delete m_cAutonTurn1;
	delete m_cAutonTurn2;
	delete m_cAutonBincher1;
	delete m_cAutonBincher2;
	delete m_cAutonArms1;
	delete m_cAutonArms2;
	delete m_cAutonArms3;
	delete m_cAutonArms4;
	delete m_cAutonArms5;
	delete m_cAutonArms6;
	delete m_cAutonRollers1;
	delete m_cAutonRollers2;
	delete m_cAutonRollers3;
	delete m_cAutonRollers4;
	delete m_cAutonRollers5;
	delete m_cAutonRollers6;
	delete m_cAutonDelay1;
	delete m_cAutonDelay2;
}

// Called just before this Command runs the first time
void AutonomousGroup8::Initialize()
{
	// Will change values once robot speed and positioning is known.
		//Delay
	m_cAutonDelay1->SetWait(
			.5);
	m_cAutonDelay2->SetWait(
			.6);

		//Pusher
	m_cAutonPusher1->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton1-Pusher-Out-Time",2), -1);

		//Lifter
			//Bincher
	m_cAutonLifter1->SetGoal(	//first
			Preferences::GetInstance()->GetDouble("Auton7-Lifter4-Time",2),
			Preferences::GetInstance()->GetDouble("Auton7-Lifter4-Threshold",15),
			Preferences::GetInstance()->GetDouble("Auton7-Lifter4-Goal",1000));
	m_cAutonLifter2->SetGoal(	//second
			Preferences::GetInstance()->GetDouble("Auton7-Lifter1-Time",2),
			Preferences::GetInstance()->GetDouble("Auton7-Lifter1-Threshold",15),
			Preferences::GetInstance()->GetDouble("Auton7-Lifter1-Goal",6385),
			AutonLifter::kIn);
	m_cAutonLifter3->SetGoal(	//third
			Preferences::GetInstance()->GetDouble("Auton7-Lifter2-Time",2),
			Preferences::GetInstance()->GetDouble("Auton7-Lifter2-Threshold",15),
			Preferences::GetInstance()->GetDouble("Auton7-Lifter2-Goal",2014));

	m_cAutonLifter4->SetGoal(	//fourth
			Preferences::GetInstance()->GetDouble("Auton7-Lifter5-Time",2),
			Preferences::GetInstance()->GetDouble("Auton7-Lifter5-Threshold",15),
			Preferences::GetInstance()->GetDouble("Auton7-Lifter5-Goal",0));
	m_cAutonLifter5->SetGoal(	//fifth
			Preferences::GetInstance()->GetDouble("Auton7-Lifter3-Time",2),
			Preferences::GetInstance()->GetDouble("Auton7-Lifter3-Threshold",15),
			Preferences::GetInstance()->GetDouble("Auton7-Lifter3-Goal",2014));
	m_cAutonLifter6->SetGoal(	//sixth
			Preferences::GetInstance()->GetDouble("Auton7-Lifter6-Time",2),
			Preferences::GetInstance()->GetDouble("Auton7-Lifter6-Threshold",15),
			Preferences::GetInstance()->GetDouble("Auton7-Lifter6-Goal",0));
	m_cAutonLifter7->SetGoal(	//seventh
			Preferences::GetInstance()->GetDouble("Auton7-Lifter7-Time",2),
			Preferences::GetInstance()->GetDouble("Auton7-Lifter7-Threshold",15),
			Preferences::GetInstance()->GetDouble("Auton7-Lifter7-Goal",2014));
	m_cAutonLifter8->SetGoal(	//eighth
			Preferences::GetInstance()->GetDouble("Auton7-Lifter8-Time",2),
			Preferences::GetInstance()->GetDouble("Auton7-Lifter8-Threshold",15),
			Preferences::GetInstance()->GetDouble("Auton7-Lifter8-Goal",0));
	m_cAutonLifter9->SetGoal(	//ninth
			Preferences::GetInstance()->GetDouble("Auton7-Lifter9-Time",2),
			Preferences::GetInstance()->GetDouble("Auton7-Lifter9-Threshold",15),
			Preferences::GetInstance()->GetDouble("Auton7-Lifter9-Goal",400));
	m_cAutonLifter10->SetGoal(
			2,
			10,
			0);


		//Driving
	m_cAutonDriveStraight0->SetGoal(
			12,
			.5,
			.5,
			1);
	m_cAutonDriveStraight1->SetGoal(
			27,
			.5,
			.65,
			1);
	m_cAutonDriveStraight2->SetGoal(
			6,
			1,
			.5,
			1);
	m_cAutonDriveStraight3->SetGoal(
			52,
			.5,
			.65,
			2,
			-7);
	m_cAutonDriveStraight4->SetGoal(
			80,
			.5,
			0.80,
			2);
	m_cAutonDriveStraight5->SetGoal(
			16,
			.5,
			0.65,
			1);
	m_cAutonDriveStraight5->SetGoal(
			37,
			0.5,
			0.65,
			1);
	m_cAutonDriveStraight6->SetGoal(
			15,
			0.5,
			0.65,
			1);
	m_cAutonDriveStraight7->SetGoal(
			-15,
			0.5,
			0.65,
			1);
	m_cAutonDriveStraight8->SetGoal(
			99,
			0.5,
			0.65,
			1);
	m_cAutonDriveStraight9->SetGoal(
			-9,
			0.5,
			-0.65,
			1);

	m_cAutonDriveTurn2->SetGoal(45, 1.5);
	m_cAutonDriveTurn3->SetGoal(-53,1.5);
	m_cAutonDriveIntake2->SetGoal(26,1,0.65,1);
	m_cAutonDriveIntake3->SetGoal(26,1,0.65,3);
	m_cAutonDriveAfterTurn2->SetGoal(53,1,0.75,2);
	m_cAutonDriveAfterTurn3->SetGoal(1,1,0.75,1);

		//Turning
	m_cAutonTurn1->SetGoal(
			-15,//-51
			0.8);
	m_cAutonTurn2->SetGoal(
			-28,
			1.1);
	m_cAutonTurn3->SetGoal(
			-75,
			2);

		//Bincher
	m_cAutonBincher1->SetDir(
			Preferences::GetInstance()->GetBoolean("Auton7-Bincher-Direction",true));
	m_cAutonBincher2->SetDir(
			Preferences::GetInstance()->GetBoolean("Auton7-Bincher2-Direction",false));

		//Intake Arms
	m_cAutonArms1->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton7-Arms-Opentime",1),
			false);
	m_cAutonArms2->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton7-Arms2-Opentime",1),
			true);
	m_cAutonArms3->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton7-Arms3-Opentime",1),
			false);
	m_cAutonArms4->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton7-Arms4-Opentime",1),
			true);
	m_cAutonArms5->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton7-Arms5-Opentime",1),
			false);
	m_cAutonArms6->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton7-Arms6-Opentime",1),
			true);

		//Rollers
	m_cAutonRollers1->SetGoal(15,  1, -1);
	m_cAutonRollers2->SetGoal(5,  -1,  1);
	m_cAutonRollers3->SetGoal(15,   1,  1);
	m_cAutonRollers4->SetGoal(15,   1, -1);
	m_cAutonRollers5->SetGoal(15,  -1, -1);
	m_cAutonRollers6->SetGoal(15,   1, -1);
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
