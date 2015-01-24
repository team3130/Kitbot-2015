#include "AutonRollers.h"

AutonRollers::AutonRollers()
{
	Requires(intake);
	m_nLeftIntake = 0;
	m_nRightIntake = 0;
	m_nTimer = 0;
	m_bRollersExecute = false;
}



// Called just before this Command runs the first time
void AutonRollers::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void AutonRollers::Execute()
{
	//determines the proposed intake status using gamepad buttons
	//buttons must be held down to maintain intake position
	//intake position will default to 0 when no buttons are pressed
	if(m_bRollersExecute){
		intake->HandleObjects(m_nLeftIntake, m_nRightIntake);
		m_nTimer -= 1;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool AutonRollers::IsFinished()
{
	return (m_nTimer <= 0);
}

// Called once after isFinished returns true
void AutonRollers::End()
{
	m_bRollersExecute = false;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonRollers::Interrupted()
{
	End();
}
