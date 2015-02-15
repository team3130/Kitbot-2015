#include "ControlLifter.h"

ControlLifter::ControlLifter()
	: manualMode(true)
{
	Requires(lifter);
}

// Called just before this Command runs the first time
void ControlLifter::Initialize()
{
	manualMode = true;
}

// Called repeatedly when this Command is scheduled to run
void ControlLifter::Execute()
{
	double thumb = -oi->gamepad->GetRawAxis(A_LIFTER);
	if(fabs(thumb) > 0.1)
	{
		manualMode = true;
		lifter->moveLifter(thumb);
	}
		else {
			bool buttonPushed = false;
			if(oi->gamepad->GetRawButton(B_PAD_A)){
				goal = 0;
				buttonPushed = true;
			} else if(oi->gamepad->GetRawButton(B_PAD_B)){
				goal = 1;
				buttonPushed = true;
			} else if(oi->gamepad->GetRawButton(B_PAD_X)){
				goal = 2;
				buttonPushed = true;
			} else if(oi->gamepad->GetRawButton(B_PAD_Y)){
				goal = 3;
				buttonPushed = true;
			}
			if(buttonPushed != buttonHold){
				buttonHold = buttonPushed;
				if(buttonPushed == true){
					timer->Start();
				}
				if(buttonPushed == false){
					if(timer->Get() <= 3){
						lifter->toSetpoint(goal);
					}else{
						if(goal == 1){
							Preferences::GetInstance()->PutInt("LifterLevel1B",lifter->m_cLiftMotor->GetPosition());
						}else if(goal == 2){
							Preferences::GetInstance()->PutInt("LifterLevel1X",lifter->m_cLiftMotor->GetPosition());
						}else if(goal == 3){
							Preferences::GetInstance()->PutInt("LifterLevel1Y",lifter->m_cLiftMotor->GetPosition());
					}
				}
			}
			else if(manualMode)
			{
				// Stop the motor if nothing happened and we're still in manual mode
				lifter->moveLifter(0);
			}
		}
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ControlLifter::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ControlLifter::End()
{
	lifter->moveLifter(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ControlLifter::Interrupted()
{
	End();
}
