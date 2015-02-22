#include "ControlBincher.h"

ControlBincher::ControlBincher()
	: m_bNewStatus(true)
{
	Requires(bincher);
	m_Button = new JoystickButton(oi->gamepad, 7);
}

ControlBincher::~ControlBincher()
{
	delete m_Button;
}

// Called just before this Command runs the first time
void ControlBincher::Initialize()
{
	m_bNewStatus = true;
	bincher->SetPinch(false);
}

// Called repeatedly when this Command is scheduled to run
void ControlBincher::Execute()
{
	if(m_Button->Get()){
		if(m_bNewStatus){
			m_bNewStatus = false;
			if(bincher->IsPinching()){
				bincher->SetPinch(false);	//if pinching, unpinch
			}else{
				bincher->SetPinch(true);	//if not pinching, pinch
			}
		}
	}else{
		m_bNewStatus = true;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ControlBincher::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void ControlBincher::End()
{
	bincher->SetPinch(false);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ControlBincher::Interrupted()
{
	End();
}
