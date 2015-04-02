#include "AutonomousGroup6.h"

AutonomousGroup6::AutonomousGroup6()
{
	m_cAutonArmsOpen1 = new AutonIntakeArms();
	m_cAutonLifterOut1 = new AutonLifter();
	m_cAutonLifterStart1 = new AutonLifter();
	m_cAutonGroupBincher = new AutonomousGroupBincher();

	//Goal: pick up a bin and put into bincher
	AddParallel(m_cAutonArmsOpen1);				//opens arms
	AddSequential(m_cAutonLifterOut1);			//Release the flaps
	AddSequential(m_cAutonLifterStart1);		//lifts bin up a bit
	AddParallel(m_cAutonGroupBincher);
}

AutonomousGroup6::~AutonomousGroup6()
{
	delete m_cAutonArmsOpen1;
	delete m_cAutonLifterOut1;
	delete m_cAutonLifterStart1;
	delete m_cAutonGroupBincher;
}

// Called just before this Command runs the first time
void AutonomousGroup6::Initialize()
{
	m_cAutonLifterOut1->SetGoal(3, 25, 750, AutonLifter::kOut);	// Release the Kraken
	m_cAutonLifterStart1->SetGoal(2, 25, 1000);	//first
	m_cAutonGroupBincher->SetGoal(5150, 2014);	// The top position and where to return the lifter to
	m_cAutonArmsOpen1->SetGoal(1, false);
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
