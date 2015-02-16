#include <Commands/ControlAntlerMoose.h>
#include "AntlerMoose.h"
#include "../RobotMap.h"

AntlerMoose::AntlerMoose()
	: Subsystem("AntlerMoose")
{
	m_cAntlers = new DoubleSolenoid(COMPRESSOR, LEFTANTLER, RIGHTANTLER);
	//false is considered to be up. TODO: Change if orientation does
	m_bAntlersDown = false;
}

AntlerMoose::~AntlerMoose(){
	delete m_cAntlers;
}

void AntlerMoose::InitDefaultCommand()
{
	SetDefaultCommand(new ControlAntlerMoose());
}

void AntlerMoose::ControlAntlers(int status)
{
	if(status == 1){
		m_cAntlers->Set(DoubleSolenoid::kForward);
		m_bAntlersDown = true;
	}else if(status == -1){
		m_cAntlers->Set(DoubleSolenoid::kReverse);
		m_bAntlersDown = false;
	}else{
		m_cAntlers->Set(DoubleSolenoid::kOff);
	}
}
