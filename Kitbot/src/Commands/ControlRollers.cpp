#include "ControlRollers.h"

ControlRollers::ControlRollers()
{
	Requires(intake);
	intakeStatus = 0;
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
		intakeStatus = 1;
	}else if(oi->gamepad->GetRawButton(B_INTAKEOUT)){
		intakeStatus = -1;
	}else{
		intakeStatus = 0;
	}

	intake->HandleObjects(intakeStatus);
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
