#include "AutonomousGroupBincher.h"

AutonomousGroupBincher::AutonomousGroupBincher()
{
	m_cAutonLifterUp = new AutonLifter();
	m_cAutonLifterDown = new AutonLifter();
	m_cAutonLifterLower = new AutonLifter();
	m_cAutonBincherOpen = new AutonBincher();
	m_cAutonBincherClamp = new AutonBincher();
	m_cAutonDelayBottom = new AutonDelay();
	m_cAutonDelayTop = new AutonDelay();
	
	AddSequential(m_cAutonBincherOpen);		//opens bincher
	AddSequential(m_cAutonLifterUp);
	AddSequential(m_cAutonBincherClamp);		//Binches bin
	AddSequential(m_cAutonDelayTop);
	AddSequential(m_cAutonLifterDown);
	AddSequential(m_cAutonDelayBottom);
	//AddSequential(m_cAutonLifterLower);			//lowers lifter
}

AutonomousGroupBincher::~AutonomousGroupBincher()
{
	delete m_cAutonLifterUp;
	delete m_cAutonLifterDown;
	delete m_cAutonLifterLower;
	delete m_cAutonBincherOpen;
	delete m_cAutonBincherClamp;
	delete m_cAutonDelayBottom;
	delete m_cAutonDelayTop;
}

// Called just before this Command runs the first time
void AutonomousGroupBincher::Initialize()
{
	//Bincher (bool bDirection)
	m_cAutonBincherOpen->SetDir(true);
	m_cAutonBincherClamp->SetDir(false);
	m_cAutonDelayBottom->SetWait(0.15);
	m_cAutonDelayTop->SetWait(0.15);
	m_cAutonLifterUp->SetGoal(3, 25, 5150, AutonLifter::kIn);	// Up to the height to clamp the bin
	m_cAutonLifterDown->SetGoal(3, 25, 0);	// All the way down to pickup the tote
	m_cAutonLifterLower->SetGoal(3, 25, 2015);	// Lower the tote when the bin is secured in the bincher
}

void AutonomousGroupBincher::SetGoal(double top, double end)
{
//	m_cAutonLifterUp->SetGoal(3, 25, top, AutonLifter::kIn);	// Up to the height to clamp the bin
//	m_cAutonLifterDown->SetGoal(3, 25, 0);	// All the way down to pickup the tote
//	m_cAutonLifterLower->SetGoal(3, 25, end);	// Lower the tote when the bin is secured in the bincher
}

// Called repeatedly when this Commsand is scheduled to run
void AutonomousGroupBincher::Execute()
{
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
