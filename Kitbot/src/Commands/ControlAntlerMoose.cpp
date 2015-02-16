#include "ControlAntlerMoose.h"

ControlAntlerMoose::ControlAntlerMoose()
{
	Requires(antlerMoose);
	m_Button = new JoystickButton(oi->gamepad, 7);
}

ControlAntlerMoose::~ControlAntlerMoose()
{
	delete m_Button;
}

// Called just before this Command runs the first time
void ControlAntlerMoose::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void ControlAntlerMoose::Execute()
{
	if(m_Button->Get()){
		if(antlerMoose->IsAntlersDown()){
			antlerMoose->ControlAntlers(-1);	//if antlers are down, move them up
		}else{
			antlerMoose->ControlAntlers(1);		//if antlers are up, move them down
		}
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
	antlerMoose->ControlAntlers(0);		//keeps antlers at current position when disabled
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ControlAntlerMoose::Interrupted()
{
	End();
}
