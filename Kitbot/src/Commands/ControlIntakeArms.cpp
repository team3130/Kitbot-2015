#include "ControlIntakeArms.h"

ControlIntakeArms::ControlIntakeArms()
{
	Requires(intakearms);
	m_bArmsExtended = true;
}

// Called just before this Command runs the first time
void ControlIntakeArms::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ControlIntakeArms::Execute()
{
	bool extB = !oi->gamepad->GetRawButton(B_PAD_Y)();
	intakearms->ControlArms(extB, extB);
	m_bArmsExtended = extB;
}

// Make this return true when this Command no longer needs to run execute()
bool ControlIntakeArms::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ControlIntakeArms::End()
{
	intakearms->ControlArms(true, true);	//Intake Arms go out when disabled
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ControlIntakeArms::Interrupted()
{
	End();
}
