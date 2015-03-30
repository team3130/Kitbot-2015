#include "AutonomousGroupBincher.h"

AutonomousGroupBincher::AutonomousGroupBincher()
{
	m_cAutonLifterUp = new AutonLifter();
	m_cAutonLifterDown = new AutonLifter();
	m_cAutonLifterLower = new AutonLifter();
	m_cAutonBincherOpen = new AutonBincher();
	m_cAutonBincherClamp = new AutonBincher();
	
	AddParallel(m_cAutonBincherOpen);		//opens bincher
	AddSequential(m_cAutonLifterDown);
	AddSequential(new WaitCommand(0.15));
	AddSequential(m_cAutonLifterUp);
	AddSequential(m_cAutonBincherClamp);		//Binches bin
	AddSequential(new WaitCommand(0.15));
	AddSequential(m_cAutonLifterLower);			//lowers lifter
}

AutonomousGroupBincher::~AutonomousGroupBincher()
{
	delete m_cAutonLifterUp;
	delete m_cAutonLifterDown;
	delete m_cAutonLifterLower;
	delete m_cAutonBincherOpen;
	delete m_cAutonBincherClamp;
}

// Called just before this Command runs the first time
void AutonomousGroupBincher::Initialize()
{
	//Bincher (bool bDirection)
	m_cAutonBincherOpen->SetDir(true);
	m_cAutonBincherClamp->SetDir(false);
}

void AutonomousGroupBincher::SetGoal(double top, double end)
{
	m_cAutonLifterDown->SetGoal(2, 25, 0);	// All the way down to pickup the tote
	m_cAutonLifterUp->SetGoal(2, 25, top);	// Up to the height to clamp the bin
	m_cAutonLifterLower->SetGoal(2, 25, end);	// Lower the tote when the bin is secured in the bincher
}

// Called repeatedly when this Commsand is scheduled to run
void AutonomousGroupBincher::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool AutonomousGroupBincher::IsFinished()
{
	return m_cAutonLifterLower->IsFinished();
}

// Called once after isFinished returns true
void AutonomousGroupBincher::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonomousGroupBincher::Interrupted()
{
	End();
}
