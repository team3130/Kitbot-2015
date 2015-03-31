#include "ControlLifter.h"

ControlLifter::ControlLifter()
	: manualMode(true)
	, buttonHold(false)
	, preset(kA)
{
	Requires(lifter);
}

// Called just before this Command runs the first time
void ControlLifter::Initialize()
{
	manualMode = true;
	buttonHold = false;
	lifter->moveLifter(0);
}

// Called repeatedly when this Command is scheduled to run
void ControlLifter::Execute()
{
	const char * presetA = "LifterLevelA";
	const char * presetB = "LifterLevelB";
	const char * presetX = "LifterLevelX";
	const char * presetY = "LifterLevelY";
	const char *s_preset = presetA;

	double thumb = -oi->gamepad->GetRawAxis(A_LIFTER);
	if(fabs(thumb) > 0.1){
		manualMode = true;
		buttonHold = false;
		lifter->moveLifter(thumb);
	}else{
		//determines whether a button has been pressed
		bool buttonPushed = false;
		if(oi->gamepad->GetRawButton(B_PAD_A)){
			preset = kA;
			s_preset = presetA;
			buttonPushed = true;
		} else if(oi->gamepad->GetRawButton(B_PAD_B)){
			preset = kB;
			s_preset = presetB;
			buttonPushed = true;
		} else if(oi->gamepad->GetRawButton(B_PAD_X)){
			preset = kX;
			s_preset = presetX;
			buttonPushed = true;
		} else if(oi->gamepad->GetRawButton(B_PAD_Y)){
			preset = kY;
			s_preset = presetY;
			buttonPushed = true;
		}

		if(buttonPushed){
			// Go to a preset position only when a button is pushed
			// Turn off the manual mode too
			manualMode = false;
			if(!buttonHold) {
				buttonHold = true;
				timer.Reset();
				timer.Start();
			}
		}
		else {
			int goal = 0;
			switch(preset) {
			case kA:
				s_preset = presetA;
				goal = 0;
				break;
			case kB:
				s_preset = presetB;
				goal = Preferences::GetInstance()->GetInt(s_preset, 1682);
				break;
			case kX:
				s_preset = presetX;
				goal = Preferences::GetInstance()->GetInt(s_preset, 983);
				break;
			case kY:
				s_preset = presetY;
				goal = Preferences::GetInstance()->GetInt(s_preset, 523);
				break;
			}

			if(buttonHold && timer.Get() > 3) {
				Preferences::GetInstance()->PutInt(s_preset, lifter->GetPosition());
				Preferences::GetInstance()->Save();
			}
			else if(manualMode){
				// Stop the motor if nothing happened and we're still in manual mode
				lifter->moveLifter(0);
			}
			else {
				lifter->toSetpoint(goal);
			}
			buttonHold = false;
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
