#include "AutonomousGroup7.h"

AutonomousGroup7::AutonomousGroup7()
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
	m_cAutonBincher1 = new AutonBincher();
	m_cAutonBincher2 = new AutonBincher();
	m_cAutonDriveStraight1 = new AutonDriveStraight();
	m_cAutonDriveStraight2 = new AutonDriveStraight();
	m_cAutonDriveStraight3 = new AutonDriveStraight();
	m_cAutonDriveStraight4 = new AutonDriveStraight();
	m_cAutonDriveStraight5 = new AutonDriveStraight();
	m_cAutonDriveStraight6 = new AutonDriveStraight();
	m_cAutonDriveStraight7 = new AutonDriveStraight();
	m_cAutonDriveStraight8 = new AutonDriveStraight();
	m_cAutonDriveStraight9 = new AutonDriveStraight();
	m_cAutonTurn1 = new AutonSmartTurn();
	m_cAutonTurn2 = new AutonSmartTurn();
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
	
	AddParallel(m_cAutonArms1);				//opens arms
	AddSequential(m_cAutonBincher1);		//opens bincher
	AddSequential(m_cAutonLifter1);			//lifts bin up
	AddSequential(m_cAutonPusher1);			//grabs bin back
	AddSequential(m_cAutonLifter2);			//lifts bin up
	AddSequential(m_cAutonBincher2);		//Binches bin
	AddSequential(m_cAutonLifter3);			//lowers lifter

	AddSequential(m_cAutonDriveStraight1);
	AddSequential(m_cAutonTurn1);
	AddSequential(m_cAutonDriveStraight2);
	AddSequential(m_cAutonArms2);
	AddSequential(m_cAutonRollers1);
	AddSequential(m_cAutonLifter4);
	AddParallel(m_cAutonLifter5);

	AddSequential(m_cAutonDriveStraight2);
	AddParallel(m_cAutonRollers2);
	AddParallel(m_cAutonDriveStraight3);
	AddSequential(m_cAutonArms3);
	AddSequential(m_cAutonDriveStraight4);
	AddParallel(m_cAutonArms4);
	AddSequential(m_cAutonRollers3);
	AddSequential(m_cAutonLifter6);
	AddParallel(m_cAutonLifter7);

	AddSequential(m_cAutonDriveStraight5);
	AddParallel(m_cAutonRollers4);
	AddParallel(m_cAutonDriveStraight6);
	AddSequential(m_cAutonArms5);
	AddSequential(m_cAutonDriveStraight7);
	AddParallel(m_cAutonArms6);
	AddSequential(m_cAutonRollers5);
	AddSequential(m_cAutonLifter8);
	AddParallel(m_cAutonLifter9);

	AddSequential(m_cAutonTurn2);
	AddSequential(m_cAutonDriveStraight8);
	AddParallel(m_cAutonRollers6);
	AddParallel(m_cAutonDriveStraight9);


}

AutonomousGroup7::~AutonomousGroup7()
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
	delete m_cAutonDriveStraight1;
	delete m_cAutonDriveStraight2;
	delete m_cAutonDriveStraight3;
	delete m_cAutonDriveStraight4;
	delete m_cAutonTurn1;
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
}

// Called just before this Command runs the first time
void AutonomousGroup7::Initialize()
{
	// Will change values once robot speed and positioning is known.
		//Pusher
	m_cAutonPusher1->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton1-Pusher-Out-Time",2), -1);

		//Lifter
			//Bincher
	m_cAutonLifter1->SetGoal(	//first
			Preferences::GetInstance()->GetDouble("Auton7-Lifter4-Time",2),
			Preferences::GetInstance()->GetDouble("Auton7-Lifter4-Threshold",15),
			Preferences::GetInstance()->GetDouble("Auton7-Lifter4-Goal",3000));
	m_cAutonLifter2->SetGoal(	//second
			Preferences::GetInstance()->GetDouble("Auton7-Lifter1-Time",2),
			Preferences::GetInstance()->GetDouble("Auton7-Lifter1-Threshold",15),
			Preferences::GetInstance()->GetDouble("Auton7-Lifter1-Goal",6385));
	m_cAutonLifter3->SetGoal(	//third
			Preferences::GetInstance()->GetDouble("Auton7-Lifter2-Time",2),
			Preferences::GetInstance()->GetDouble("Auton7-Lifter2-Threshold",15),
			Preferences::GetInstance()->GetDouble("Auton7-Lifter2-Goal",2000));

	m_cAutonLifter4->SetGoal(	//fourth
			Preferences::GetInstance()->GetDouble("Auton7-Lifter5-Time",2),
			Preferences::GetInstance()->GetDouble("Auton7-Lifter5-Threshold",15),
			Preferences::GetInstance()->GetDouble("Auton7-Lifter5-Goal",500));
	m_cAutonLifter5->SetGoal(	//fifth
			Preferences::GetInstance()->GetDouble("Auton7-Lifter3-Time",2),
			Preferences::GetInstance()->GetDouble("Auton7-Lifter3-Threshold",15),
			Preferences::GetInstance()->GetDouble("Auton7-Lifter3-Goal",3000));
	m_cAutonLifter6->SetGoal(	//sixth
			Preferences::GetInstance()->GetDouble("Auton7-Lifter6-Time",2),
			Preferences::GetInstance()->GetDouble("Auton7-Lifter6-Threshold",15),
			Preferences::GetInstance()->GetDouble("Auton7-Lifter6-Goal",500));
	m_cAutonLifter7->SetGoal(	//seventh
			Preferences::GetInstance()->GetDouble("Auton7-Lifter7-Time",2),
			Preferences::GetInstance()->GetDouble("Auton7-Lifter7-Threshold",15),
			Preferences::GetInstance()->GetDouble("Auton7-Lifter7-Goal",3000));
	m_cAutonLifter8->SetGoal(	//eighth
			Preferences::GetInstance()->GetDouble("Auton7-Lifter8-Time",2),
			Preferences::GetInstance()->GetDouble("Auton7-Lifter8-Threshold",15),
			Preferences::GetInstance()->GetDouble("Auton7-Lifter8-Goal",500));
	m_cAutonLifter9->SetGoal(	//ninth
			Preferences::GetInstance()->GetDouble("Auton7-Lifter9-Time",2),
			Preferences::GetInstance()->GetDouble("Auton7-Lifter9-Threshold",15),
			Preferences::GetInstance()->GetDouble("Auton7-Lifter9-Goal",2000));


		//Driving
	m_cAutonDriveStraight1->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton7-Distance-Tote1",29),
			Preferences::GetInstance()->GetDouble("Auton7-Tolerance-Tote1",.5),
			Preferences::GetInstance()->GetDouble("Auton7-Speed-Tote1",.65),
			Preferences::GetInstance()->GetDouble("Auton7-Timeout-Tote1",1));
	m_cAutonDriveStraight2->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton7-Distance-Tote2",13),
			Preferences::GetInstance()->GetDouble("Auton7-Tolerance-Tote2",.5),
			Preferences::GetInstance()->GetDouble("Auton7-Speed-Tote2",.65),
			Preferences::GetInstance()->GetDouble("Auton7-Timeout-Tote2",1));
	m_cAutonDriveStraight3->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton7-Distance-Tote3",33),
			Preferences::GetInstance()->GetDouble("Auton7-Tolerance-Tote3",.5),
			Preferences::GetInstance()->GetDouble("Auton7-Speed-Tote3",.65),
			Preferences::GetInstance()->GetDouble("Auton7-Timeout-Tote3",1));
	m_cAutonDriveStraight4->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton7-Distance-Tote4",30),
			Preferences::GetInstance()->GetDouble("Auton7-Tolerance-Tote4",.5),
			Preferences::GetInstance()->GetDouble("Auton7-Speed-Tote4",0.65),
			Preferences::GetInstance()->GetDouble("Auton7-Timeout-Tote4",1));
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
			15,
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

		//Turning
	m_cAutonTurn1->SetGoal(
			-31,
			1);
	m_cAutonTurn2->SetGoal(
			-90,
			1);

		//Bincher
	m_cAutonBincher1->SetDir(
			Preferences::GetInstance()->GetBoolean("Auton7-Bincher-Direction",true));
	m_cAutonBincher2->SetDir(
			Preferences::GetInstance()->GetBoolean("Auton7-Bincher2-Direction",false));

		//Intake Arms
	m_cAutonArms1->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton7-Arms-Opentime",10),
			false);
	m_cAutonArms2->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton7-Arms2-Opentime",2),
			true);
	m_cAutonArms3->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton7-Arms3-Opentime",2),
			false);
	m_cAutonArms4->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton7-Arms4-Opentime",2),
			true);
	m_cAutonArms5->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton7-Arms5-Opentime",2),
			false);
	m_cAutonArms6->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton7-Arms6-Opentime",2),
			true);

		//Rollers
	m_cAutonRollers1->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton7-Rollers1-Runtime",2),
			1,
			-1);
	m_cAutonRollers2->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton7-Rollers2-Runtime",2),
			-1,
			1);
	m_cAutonRollers3->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton7-Rollers3-Runtime",2),
			1,
			-1);
	m_cAutonRollers4->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton7-Rollers4-Runtime",2),
			-1,
			1);
	m_cAutonRollers5->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton7-Rollers5-Runtime",2),
			1,
			-1);
	m_cAutonRollers6->SetGoal(
			Preferences::GetInstance()->GetDouble("Auton7-Rollers6-Runtime",2),
			-1,
			1);
}

// Called repeatedly when this Commsand is scheduled to run
void AutonomousGroup7::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool AutonomousGroup7::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void AutonomousGroup7::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonomousGroup7::Interrupted()
{
	End();
}
