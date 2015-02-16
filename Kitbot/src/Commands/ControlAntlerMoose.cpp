#include "ControlAntlerMoose.h"

ControlAntlerMoose::ControlAntlerMoose()
	: m_bNewStatusL(true)
	, m_bNewStatusR(true)
{
	Requires(antlerMoose);
	m_ButtonLeft = new JoystickButton(oi->gamepad, 5);
	m_ButtonRight = new JoystickButton(oi->gamepad, 6);
}

ControlAntlerMoose::~ControlAntlerMoose()
{
	delete m_ButtonLeft;
	delete m_ButtonRight;
}

// Called just before this Command runs the first time
void ControlAntlerMoose::Initialize()
{
	m_bNewStatusL = true;
	m_bNewStatusR = true;
}

// Called repeatedly when this Command is scheduled to run
void ControlAntlerMoose::Execute()
{
	if(m_ButtonLeft->Get()){
		if(m_bNewStatusL){
			m_bNewStatusL = false;
			if(antlerMoose->IsLeftAntlerDown()){
				antlerMoose->ControlLeftAntler(DoubleSolenoid::kReverse);	//if antlers down, move up
			}else{
				antlerMoose->ControlLeftAntler(DoubleSolenoid::kForward);	//if antlers up, move down
			}
		}
	}else{
		m_bNewStatusL = true;
	}

	if(m_ButtonRight->Get()){
		if(m_bNewStatusR){
			m_bNewStatusR = false;
			if(antlerMoose->IsRightAntlerDown()){
				antlerMoose->ControlRightAntler(DoubleSolenoid::kReverse);//if antlers down, move up
			}else{
				antlerMoose->ControlRightAntler(DoubleSolenoid::kForward);//if antlers up, move down
			}
		}
	}else{
		m_bNewStatusR = true;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ControlAntlerMoose::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ControlAntlerMoose::End()
{
	antlerMoose->ControlLeftAntler(DoubleSolenoid::kOff);	//keeps antlers at current position when disabled
	antlerMoose->ControlRightAntler(DoubleSolenoid::kOff);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ControlAntlerMoose::Interrupted()
{
	End();
}
