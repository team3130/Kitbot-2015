#include "AutonomousGroup7.h"

AutonomousGroup7::AutonomousGroup7()
{
	//Goal: intake all yellow totes
	lft_AutonDown1 = new AutonLifter();
	lft_AutonDown2 = new AutonLifter();
	lft_AutonDown3 = new AutonLifter();
	lft_AutonUp1 = new AutonLifter();
	lft_AutonUp2 = new AutonLifter();
	lft_AutonUp3 = new AutonLifter();

	drv_AutonToBin1 = new AutonDriveStraight();
	drv_AutonToBin2 = new AutonDriveStraight();
	drv_AutonToteIn1 = new AutonDriveStraight();
	drv_AutonToteIn2 = new AutonDriveStraight();
	drv_AutonZone1 = new AutonDriveStraight();
	drv_AutonZone2 = new AutonDriveStraight();
	drv_AutonBack1 = new AutonDriveStraight();
	drv_AutonBack2 = new AutonDriveStraight();

	trn_AutonKnockBin1 = new AutonSmartTurn();
	trn_AutonKnockBin2 = new AutonSmartTurn();
	trn_AutonZoneTurn1 = new AutonSmartTurn();

	whl_AutonIntakeIn1 = new AutonRollers();
	whl_AutonIntakeIn2 = new AutonRollers();
	whl_AutonIntakeIn0 = new AutonRollers();
	whl_AutonIntakeOut1 = new AutonRollers();

	dly_BackDelay1 = new AutonDelay();
	dly_BackDelay2 = new AutonDelay();

	AddParallel(whl_AutonIntakeIn0);
	AddParallel(lft_AutonUp1);
	AddSequential(drv_AutonBack1);
	AddSequential(dly_BackDelay1);
	AddSequential(drv_AutonToBin1);
	AddSequential(trn_AutonKnockBin1);

	AddParallel(whl_AutonIntakeIn1);
	AddSequential(drv_AutonToteIn1);
	AddSequential(lft_AutonDown1);
	AddParallel(lft_AutonUp2);
	AddSequential(drv_AutonBack2);
	AddSequential(dly_BackDelay2);
	AddSequential(drv_AutonToBin2);
	AddSequential(trn_AutonKnockBin2);

	AddParallel(whl_AutonIntakeIn2);
	AddSequential(drv_AutonToteIn2);
	AddSequential(lft_AutonDown2);
	AddParallel(lft_AutonUp3);

	AddSequential(trn_AutonZoneTurn1);
	AddSequential(drv_AutonZone1);
	AddParallel(whl_AutonIntakeOut1);
	AddParallel(lft_AutonDown3);
	AddSequential(drv_AutonZone2);


}

AutonomousGroup7::~AutonomousGroup7()
{
	delete lft_AutonDown1;
	delete lft_AutonDown2;
	delete lft_AutonDown3;
	delete lft_AutonUp1;
	delete lft_AutonUp2;
	delete lft_AutonUp3;
	delete drv_AutonToBin1;
	delete drv_AutonToBin2;
	delete drv_AutonToteIn1;
	delete drv_AutonToteIn2;
	delete drv_AutonZone1;
	delete drv_AutonZone2;
	delete drv_AutonBack1;
	delete drv_AutonBack2;
	delete trn_AutonKnockBin1;
	delete trn_AutonKnockBin2;
	delete trn_AutonZoneTurn1;
	delete whl_AutonIntakeIn1;
	delete whl_AutonIntakeIn2;
	delete whl_AutonIntakeIn0;
	delete whl_AutonIntakeOut1;
	delete dly_BackDelay1;
	delete dly_BackDelay2;
}

// Called just before this Command runs the first time
void AutonomousGroup7::Initialize()
{
	// Will change values once robot speed and positioning is known.
	lft_AutonDown1->SetGoal(2,25,2);
	lft_AutonDown2->SetGoal(2,25,2);
	lft_AutonDown3->SetGoal(0,20,2);
	lft_AutonUp1->SetGoal(2,35,1400);
	lft_AutonUp2->SetGoal(2,35,1400);
	lft_AutonUp3->SetGoal(2,35,100);

	drv_AutonToBin1->SetGoal(57,4,.75,3,30);
	drv_AutonToBin2->SetGoal(55,4,.70,3,40);
	drv_AutonToteIn1->SetGoal(48,6,.6,3);
	drv_AutonToteIn2->SetGoal(48,7,.55,3);
	drv_AutonZone1->SetGoal(82,3,.85,3);
	drv_AutonZone2->SetGoal(-12,1,.5,2);
	drv_AutonBack1->SetGoal(-16,7,.55,3);
	drv_AutonBack2->SetGoal(-17,5,.55,5);

	trn_AutonKnockBin1->SetGoal(-60,1,2);
	trn_AutonKnockBin2->SetGoal(-55,1,2);
	trn_AutonZoneTurn1->SetGoal(100,1,2);

	whl_AutonIntakeIn1->SetGoal(5,1,-1);
	whl_AutonIntakeIn2->SetGoal(5,1,-1);
	whl_AutonIntakeIn0->SetGoal(3,1,-1);
	whl_AutonIntakeOut1->SetGoal(5,-1,1);

	dly_BackDelay1->SetWait(0.125);
	dly_BackDelay2->SetWait(0.125);

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
