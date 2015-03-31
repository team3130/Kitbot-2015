#include "AutonomousGroup8.h"

//Goal: pick up a bin into bincher, then intake all yellow totes
AutonomousGroup8::AutonomousGroup8()
{
	m_cAutonGroupBincher = new AutonomousGroupBincher();
	m_cAutonLifterOut1 = new AutonLifter();
	m_cAutonLifterStart1 = new AutonLifter();
	m_cAutonLifterGrab1 = new AutonLifter();
	m_cAutonWaitForBin = new AutonWaitForFinished(5.0);	// Parameter is a regular timeout
	m_cAutonWaitForBincher = new AutonWaitForFinished(5.0);
	m_cAutonWaitForReload2 = new AutonWaitForFinished(5.0);
	m_cAutonWaitForReload3 = new AutonWaitForFinished(5.0);
	m_cAutonReload2 = new AutonomousGroupReload();
	m_cAutonReload3 = new AutonomousGroupReload();
	m_cAutonLifterDrop = new AutonLifter();
	m_cAutonApproach1 = new AutonDriveStraight();
	m_cAutonDriveIntake1 = new AutonDriveStraight();
	m_cAutonApproach2 = new AutonDriveStraight();
	m_cAutonDriveAutozone = new AutonDriveStraight();
	m_cAutonDriveBackout = new AutonDriveStraight();
	m_cAutonDriveIntake2 = new AutonDriveStraight();
	m_cAutonDriveIntake3 = new AutonDriveStraight();
	m_cAutonApproach3 = new AutonDriveStraight();
	m_cAutonTurn1 = new AutonSmartTurn();
	m_cAutonTurn2 = new AutonSmartTurn();
	m_cAutonTurn3 = new AutonSmartTurn();
	m_cAutonArmsOpen1 = new AutonIntakeArms();
	m_cAutonArmsClose1 = new AutonIntakeArms();
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
	
	AddParallel(m_cAutonArmsOpen1);				//opens arms
	AddSequential(m_cAutonLifterOut1);			//Release the flaps
	AddSequential(m_cAutonLifterStart1);		//lifts bin up a bit
	AddParallel(m_cAutonGroupBincher);
	//AddParallel(m_cAutonLifterGrab1);			//lifts bin up and pull it in

	AddSequential(m_cAutonTurn1);
	AddParallel(m_cAutonRollers1);
	AddSequential(m_cAutonApproach1);			//Step forward to the tote
	AddSequential(m_cAutonArmsClose1);			//Close arms
	AddParallel(m_cAutonDriveIntake1);			//Go forward and suck the tote

	//AddSequential(m_cAutonWaitForBin);

	AddSequential(m_cAutonApproach2);	// Approach the second set
	AddParallel(m_cAutonRollersOut2);
	AddSequential(m_cAutonTurn2);
//	AddSequential(m_cAutonArmsOpen2);
	AddSequential(m_cAutonWaitForBincher);
	AddParallel(m_cAutonRollersIn2);
	AddSequential(m_cAutonDriveIntake2);
	AddSequential(m_cAutonArmsClose2);	// This must be sequential to use its timer to suck the tote in
	AddParallel(m_cAutonReload2);

	AddSequential(m_cAutonApproach3);
	AddParallel(m_cAutonRollersOut3);
	AddSequential(m_cAutonTurn3);
//	AddSequential(m_cAutonArmsOpen3);
	AddParallel(m_cAutonRollersIn3);
	AddSequential(m_cAutonDriveIntake3);
	AddSequential(m_cAutonArmsClose3);	// This must be sequential to use its timer to suck the tote in
	AddSequential(m_cAutonWaitForReload2);
	AddParallel(m_cAutonReload3);

	AddSequential(m_cAutonDriveAutozone);	// Turn and drive toward Autozone
	AddSequential(m_cAutonWaitForReload3);
	AddParallel(m_cAutonLifterDrop);	// Drop the stack
	AddParallel(m_cAutonRollersEject);	// Spit the stack out
	AddSequential(m_cAutonDriveBackout); // Backout
}

AutonomousGroup8::~AutonomousGroup8()
{
	delete m_cAutonLifterOut1;
	delete m_cAutonLifterStart1;
	delete m_cAutonLifterGrab1;
	delete m_cAutonWaitForBin;
	delete m_cAutonWaitForBincher;
	delete m_cAutonWaitForReload2;
	delete m_cAutonWaitForReload3;
	delete m_cAutonGroupBincher;
	delete m_cAutonReload2;
	delete m_cAutonReload3;
	delete m_cAutonLifterDrop;
	delete m_cAutonApproach1;
	delete m_cAutonDriveIntake1;
	delete m_cAutonApproach2;
	delete m_cAutonApproach3;
	delete m_cAutonDriveAutozone;
	delete m_cAutonDriveBackout;
	delete m_cAutonTurn1;
	delete m_cAutonTurn2;
	delete m_cAutonTurn3;
	delete m_cAutonArmsOpen1;
	delete m_cAutonArmsClose1;
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
}

// Called just before this Command runs the first time
void AutonomousGroup8::Initialize()
{
		//Lifter (double timeout, double thresh, double goal, PushDirection push=kNone)
			//Bincher
	m_cAutonLifterOut1->SetGoal(3, 25, 750, AutonLifter::kOut);	// Release the Kraken
	m_cAutonLifterStart1->SetGoal(2, 25, 1000);	//first
	m_cAutonLifterGrab1->SetGoal(3, 25, 2400, AutonLifter::kIn);	//second
	m_cAutonWaitForBin->SetGoal(m_cAutonLifterGrab1);
	m_cAutonGroupBincher->SetGoal(5150, 2014);	// The top position and where to return the lifter to
	m_cAutonWaitForBincher->SetGoal(m_cAutonGroupBincher);

	m_cAutonReload2->SetGoal(2014);
	m_cAutonWaitForReload2->SetGoal(m_cAutonReload2);
	m_cAutonReload3->SetGoal(400);
	m_cAutonWaitForReload3->SetGoal(m_cAutonReload3);
	m_cAutonLifterDrop->SetGoal(2, 20, 0);


		//Driving (double dist, double thresh, double ispeed, double timeout, double angle=0)
	m_cAutonApproach1->SetGoal(27, .5, .65, 1);
	m_cAutonDriveIntake1->SetGoal(6, 1, .5, 1);
	m_cAutonApproach2->SetGoal(52, .5,	.70, 2, -35); // This was -7 when Turn2(-28) was active
	m_cAutonDriveAutozone->SetGoal(90, .5, 0.85, 3, -75);
	m_cAutonDriveBackout->SetGoal(-15, 0.5, 0.75, 1);

	m_cAutonDriveIntake2->SetGoal(50,1,0.65,2);
	m_cAutonApproach3->SetGoal(29,1,0.70,2);
	m_cAutonDriveIntake3->SetGoal(50,1,0.75,2);

		//Turning (double angle, double timeout, double tolerance=1.0)
	m_cAutonTurn1->SetGoal(-15, 0.8);
	m_cAutonTurn2->SetGoal(47, 1.5);
	m_cAutonTurn3->SetGoal(-50, 1.5);

		//Intake Arms (double timeout, bool extend)
	m_cAutonArmsOpen1->SetGoal(1, false);
	m_cAutonArmsClose1->SetGoal(0.25, true);
	m_cAutonArmsOpen2->SetGoal(1, false);
	m_cAutonArmsClose2->SetGoal(0.4, true);
	m_cAutonArmsOpen3->SetGoal(1, false);
	m_cAutonArmsClose3->SetGoal(0.4, true);

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
