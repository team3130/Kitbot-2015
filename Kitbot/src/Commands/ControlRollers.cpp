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
	if(oi->stickR->GetRawButton(B_INTAKEIN)){
		preset = kIn;
	}else if(oi->stickR->GetRawButton(B_INTAKEOUT)){
		preset = kOut;
	}else if(oi->stickR->GetRawButton(B_INTAKEROTATECCW)){
		preset = kCCW;
	}else if(oi->stickR->GetRawButton(B_INTAKEROTATECW)){
		preset = kCW;
	}else{
		preset = kIdle;
	}

	switch(preset) {
		case kIn:
			m_nLeftIntake = 1;
			m_nRightIntake = -1;
			break;
		case kOut:
			m_nLeftIntake = -0.5;
			m_nRightIntake = 0.5;
			break;
		case kCCW:
			m_nLeftIntake = 1;
			m_nRightIntake = 1;
			break;
		case kCW:
			m_nLeftIntake = -1;
			m_nRightIntake = -1;
			break;
		case kIdle:
			m_nLeftIntake = 0;
			m_nRightIntake = 0;
			break;
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
