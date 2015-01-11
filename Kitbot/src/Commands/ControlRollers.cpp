#include "ControlRollers.h"

ControlRollers::ControlRollers()
{
	Requires(intake);
	m_nLeftIntake = 0;
	m_nRightIntake = 0;
}

// Called just before this Command runs the first time
void ControlRollers::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ControlRollers::Execute()
{
	//determines the proposed intake status using gamepad buttons
	//buttons must be held down to maintain intake position
	//intake position will default to 0 when no buttons are pressed
	if(oi->gamepad->GetRawButton(B_INTAKEIN)){
		m_nLeftIntake = 1;
		m_nRightIntake = 1;
	}else if(oi->gamepad->GetRawButton(B_INTAKEOUT)){
		m_nLeftIntake = -1;
		m_nRightIntake = -1;
	}else if(oi->gamepad->GetRawButton(B_INTAKEROTATECCW)){
		m_nLeftIntake = 1;
		m_nRightIntake = -1;
	}else if(oi->gamepad->GetRawButton(B_INTAKEROTATECW)){
		m_nLeftIntake = -1;
		m_nRightIntake = 1;
	}else{
		m_nLeftIntake = 0;
		m_nRightIntake = 0;
	}

	intake->HandleObjects(m_nLeftIntake, m_nRightIntake);
}

// Make this return true when this Command no longer needs to run execute()
bool ControlRollers::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ControlRollers::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ControlRollers::Interrupted()
{

}
