#include "ControlAntlerMoose.h"

ControlAntlerMoose::ControlAntlerMoose()
{
	Requires(antlerMoose);
	m_Button = new JoystickButton(oi->gamepad, 7);
	//m_ButtonLeft = new JoystickButton(oi->gamepad, 5);
	//m_ButtonRight = new JoystickButton(oi->gamepad, 6);
}

ControlAntlerMoose::~ControlAntlerMoose()
{
	delete m_Button;
	//delete m_ButtonLeft;
	//delete m_ButtonRight;
}

// Called just before this Command runs the first time
void ControlAntlerMoose::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ControlAntlerMoose::Execute()
{
	int status = 0;
	if(m_Button->Get()){
		status = 1;
	}else{
		status = -1;
	}
	antlerMoose->ControlAntlers(status);
	/*if(m_ButtonLeft->Get()){
		if(antlerMoose->IsLeftDown()){
			antlerMoose->ControlLeftAntler(false);
		}else{
			antlerMoose->ControlLeftAntler(true);
		}
	}
	if(m_ButtonRight->Get()){
		if(antlerMoose->IsRightDown()){
			antlerMoose->ControlRightAntler(false);
		}else{
			antlerMoose->ControlRightAntler(true);
		}
	}
	*/
}

// Make this return true when this Command no longer needs to run execute()
bool ControlAntlerMoose::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ControlAntlerMoose::End()
{
	antlerMoose->ControlAntlers(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ControlAntlerMoose::Interrupted()
{
	End();
}
