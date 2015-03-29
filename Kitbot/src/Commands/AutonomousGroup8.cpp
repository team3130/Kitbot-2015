#include "AutonomousGroup8.h"

AutonomousGroup8::AutonomousGroup8()
{
	//Goal: pick up a bin into bincher, then intake all yellow totes
	m_cAutonLifter1 = new AutonLifter();
	m_cAutonLifter2 = new AutonLifter();
	m_cAutonLifter3 = new AutonLifter();
	m_cAutonLifter4 = new AutonLifter();
	m_cAutonLifter5 = new AutonLifter();
	m_cAutonLifterDown2 = new AutonLifter();
	m_cAutonLifterUp2 = new AutonLifter();
	m_cAutonLifterDown3 = new AutonLifter();
	m_cAutonLifterUp3 = new AutonLifter();
	m_cAutonLifterDrop = new AutonLifter();
	m_cAutonBincher1 = new AutonBincher();
	m_cAutonBincher2 = new AutonBincher();
	m_cAutonDriveStraight0 = new AutonDriveStraight();
	m_cAutonDriveStraight1 = new AutonDriveStraight();
	m_cAutonDriveStraight2 = new AutonDriveStraight();
	m_cAutonApproach2 = new AutonDriveStraight();
	m_cAutonDriveAutozone = new AutonDriveStraight();
	m_cAutonDriveStraight5 = new AutonDriveStraight();
	m_cAutonDriveStraight6 = new AutonDriveStraight();
	m_cAutonDriveBackout = new AutonDriveStraight();
	m_cAutonDriveStraight8 = new AutonDriveStraight();
	m_cAutonDriveStraight9 = new AutonDriveStraight();
	m_cAutonDriveTurn2 = new AutonSmartTurn();
	m_cAutonDriveTurn3 = new AutonSmartTurn();
	m_cAutonDriveIntake2 = new AutonDriveStraight();
	m_cAutonDriveIntake3 = new AutonDriveStraight();
	m_cAutonApproach3 = new AutonDriveStraight();
	m_cAutonDriveAfterTurn3 = new AutonDriveStraight();
	m_cAutonTurn1 = new AutonSmartTurn();
	m_cAutonTurn2 = new AutonSmartTurn();
	m_cAutonTurn3 = new AutonSmartTurn();
	m_cAutonArms1 = new AutonIntakeArms();
	m_cAutonArms2 = new AutonIntakeArms();
	m_cAutonArmsOpen2 = new AutonIntakeArms();
	m_cAutonArmsClose2 = new AutonIntakeArms();
	m_cAutonArmsOpen3 = new AutonIntakeArms();
	m_cAutonArmsClose3 = new AutonIntakeArms();
	m_cAutonRollers1 = new AutonRollers();
	m_cAutonRollersEject = new AutonRollers();
	m_cAutonRollersOut2 = new AutonRollers();
	m_cAutonRollersIn2 = new AutonRollers();
	m_cAutonRollersOut3 = new AutonRollers();
	m_cAutonRollersIn3 = new AutonRollers();
	m_cAutonDelayBottom = new AutonDelay();
	m_cAutonDelaySuck = new AutonDelay();
	
	AddParallel(m_cAutonArms1);				//opens arms
	AddSequential(m_cAutonBincher1);		//opens bincher
	AddSequential(m_cAutonLifter1);			//lifts bin up
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
	AddSequential(m_cAutonDelayBottom);
	AddParallel(m_cAutonLifter5);

	AddSequential(m_cAutonApproach2);	// Approach the second set
	AddParallel(m_cAutonRollersOut2);
	AddSequential(m_cAutonDriveTurn2);
	AddSequential(m_cAutonArmsOpen2);
	AddParallel(m_cAutonRollersIn2);
	AddSequential(m_cAutonDriveIntake2);
	AddSequential(m_cAutonArmsClose2);	// This must be sequential to use its timer to suck the tote in
	AddSequential(m_cAutonLifterDown2);
	AddSequential(m_cAutonDelayBottom);
	AddParallel(m_cAutonLifterUp2);

	AddSequential(m_cAutonApproach3);
	AddParallel(m_cAutonRollersOut3);
	AddSequential(m_cAutonDriveTurn3);
	AddSequential(m_cAutonArmsOpen3);
	AddParallel(m_cAutonRollersIn3);
	AddSequential(m_cAutonDriveIntake3);
	AddSequential(m_cAutonArmsClose3);	// This must be sequential to use its timer to suck the tote in
	AddSequential(m_cAutonLifterDown3);
	AddSequential(m_cAutonDelayBottom);
	AddSequential(m_cAutonLifterUp3);
	//AddSequential(m_cAutonTurn3);

	AddSequential(m_cAutonDriveAutozone);	// Turn and drive toward Autozone
	AddSequential(m_cAutonLifterDrop);	// Drop the stack
	AddParallel(m_cAutonRollersEject);	// Spit the stack out
	AddSequential(m_cAutonDriveBackout); // Backout

}

AutonomousGroup8::~AutonomousGroup8()
{
	delete m_cAutonLifter1;
	delete m_cAutonLifter2;
	delete m_cAutonLifter3;
	delete m_cAutonLifter4;
	delete m_cAutonLifter5;
	delete m_cAutonLifterDown2;
	delete m_cAutonLifterUp2;
	delete m_cAutonLifterDown3;
	delete m_cAutonLifterUp3;
	delete m_cAutonLifterDrop;
	delete m_cAutonDriveStraight0;
	delete m_cAutonDriveStraight1;
	delete m_cAutonDriveStraight2;
	delete m_cAutonApproach2;
	delete m_cAutonApproach3;
	delete m_cAutonDriveAutozone;
	delete m_cAutonDriveStraight5;
	delete m_cAutonDriveStraight6;
	delete m_cAutonDriveBackout;
	delete m_cAutonDriveStraight8;
	delete m_cAutonDriveStraight9;
	delete m_cAutonTurn1;
	delete m_cAutonTurn2;
	delete m_cAutonBincher1;
	delete m_cAutonBincher2;
	delete m_cAutonArms1;
	delete m_cAutonArms2;
	delete m_cAutonArmsOpen2;
	delete m_cAutonArmsClose2;
	delete m_cAutonArmsOpen3;
	delete m_cAutonArmsClose3;
	delete m_cAutonRollers1;
	delete m_cAutonRollersEject;
	delete m_cAutonRollersOut2;
	delete m_cAutonRollersIn2;
	delete m_cAutonRollersOut3;
	delete m_cAutonRollersIn3;
	delete m_cAutonDelayBottom;
	delete m_cAutonDelaySuck;
}

// Called just before this Command runs the first time
void AutonomousGroup8::Initialize()
{
	// Will change values once robot speed and positioning is known.
		//Delay
	m_cAutonDelayBottom->SetWait(.5);
	m_cAutonDelaySuck->SetWait(.6);

		//Lifter
			//Bincher
	m_cAutonLifter1->SetGoal(2, 15, 1000);	//first
	m_cAutonLifter2->SetGoal(2, 15, 6385, AutonLifter::kIn);	//second
	m_cAutonLifter3->SetGoal(2, 15, 2014);	//third

	m_cAutonLifter4->SetGoal(2, 15, 0);	//fourth
	m_cAutonLifter5->SetGoal(2, 15, 2014);	//fifth
	m_cAutonLifterDown2->SetGoal(2, 15, 0);	//sixth
	m_cAutonLifterUp2->SetGoal(2, 15, 2014);	//seventh
	m_cAutonLifterDown3->SetGoal(2, 15, 0);	//eighth
	m_cAutonLifterUp3->SetGoal(2, 15, 400);	//ninth
	m_cAutonLifterDrop->SetGoal(2, 10, 0);


		//Driving (double dist, double thresh, double ispeed, double timeout, double angle=0)
	m_cAutonDriveStraight0->SetGoal(12, .5, .5, 1);
	m_cAutonDriveStraight1->SetGoal(27, .5, .65, 1);
	m_cAutonDriveStraight2->SetGoal(6, 1, .5, 1);
	m_cAutonApproach2->SetGoal(52, .5,	.65, 2, -7);
	m_cAutonDriveAutozone->SetGoal(80, .5, 0.80, 3, -75);
	m_cAutonDriveStraight5->SetGoal(16, .5, 0.65, 1);
	m_cAutonDriveStraight5->SetGoal(37, 0.5, 0.65, 1);
	m_cAutonDriveStraight6->SetGoal(15, 0.5, 0.65, 1);
	m_cAutonDriveBackout->SetGoal(-15, 0.5, 0.65, 1);
	m_cAutonDriveStraight8->SetGoal(0, 0.5, 0.65, 1);
	m_cAutonDriveStraight9->SetGoal(0, 0.5, 0.65, 1);

	m_cAutonDriveTurn2->SetGoal(45, 1.5);
	m_cAutonDriveTurn3->SetGoal(-53,1.5);
	m_cAutonDriveIntake2->SetGoal(26,1,0.65,1);
	m_cAutonDriveIntake3->SetGoal(26,1,0.65,3);
	m_cAutonApproach3->SetGoal(53,1,0.75,2);
	m_cAutonDriveAfterTurn3->SetGoal(1,1,0.75,1);

		//Turning (double angle, double timeout, double tolerance=1.0)
	m_cAutonTurn1->SetGoal(-15, 0.8);
	m_cAutonTurn2->SetGoal(-28, 1.1);
	m_cAutonTurn3->SetGoal(-75, 2);

		//Bincher (bool bDirection)
	m_cAutonBincher1->SetDir(true);
	m_cAutonBincher2->SetDir(false);

		//Intake Arms (double timeout, bool extend)
	m_cAutonArms1->SetGoal(1, false);
	m_cAutonArms2->SetGoal(1, true);
	m_cAutonArmsOpen2->SetGoal(1, false);
	m_cAutonArmsClose2->SetGoal(1, true);
	m_cAutonArmsOpen3->SetGoal(1, false);
	m_cAutonArmsClose3->SetGoal(1, true);

		//Rollers (double timeout, double leftStatus, double rightStatus)
	m_cAutonRollers1->SetGoal(15,  1, -1);
	m_cAutonRollersEject->SetGoal(5,  -1,  1);
	m_cAutonRollersOut2->SetGoal(15,   1,  1);
	m_cAutonRollersIn2->SetGoal(15,   1, -1);
	m_cAutonRollersOut3->SetGoal(15,  -1, -1);
	m_cAutonRollersIn3->SetGoal(15,   1, -1);
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
