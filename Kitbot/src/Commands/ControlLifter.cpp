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
	buttonHold = false;
}

// Called repeatedly when this Command is scheduled to run
void ControlLifter::Execute()
{
	//determines manual control
	double thumb = -oi->gamepad->GetRawAxis(A_LIFTER);
	if(fabs(thumb) > 0.1){
		manualMode = true;
		lifter->moveLifter(thumb);
	}else{
		//determines whether a button has been pressed
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

		//kept in case weapons officer wants default
		/*if(buttonPushed){
			// Go to a preset position only when a button is pushed
			// Turn off the manual mode too
			manualMode = false;
			lifter->toSetpoint(goal);
		}*/

		//everytime button changes from previous state deactivates manual mode and sets new previous state
		if(buttonPushed != buttonHold){
			manualMode = false;
			buttonHold = buttonPushed;
			//if button is being pressed, reset and start timer
			if(buttonPushed){
				timer->Reset();
				timer->Start();
			}else{	//if button is being released, check time and either move to goal
				if(timer->Get() <= 3){
					lifter->toSetpoint(goal);
				}else{	//or change specific preset to current lifter position
					if(goal == 1){
						Preferences::GetInstance()->PutInt("LifterLevel1B",lifter->GetPosition());
					}else if(goal == 2){
						Preferences::GetInstance()->PutInt("LifterLevel1X",lifter->GetPosition());
					}else if(goal == 3){
						Preferences::GetInstance()->PutInt("LifterLevel1Y",lifter->GetPosition());
					}
				}
			}
		}else if(manualMode){
			// Stop the motor if nothing happened and we're still in manual mode
			lifter->moveLifter(0);
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
