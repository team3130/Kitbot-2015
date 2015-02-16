#include <Commands/ControlAntlerMoose.h>
#include "AntlerMoose.h"
#include "../RobotMap.h"

AntlerMoose::AntlerMoose()
	: Subsystem("AntlerMoose")
{
	m_cAntlers = new DoubleSolenoid(COMPRESSOR, LEFTANTLER, RIGHTANTLER);
	m_bAntlersDown = false;					//false is considered to be up
	m_cAntlers->Set(DoubleSolenoid::kOff);	//initially idles
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
		m_cAntlers->Set(DoubleSolenoid::kForward);	//1 is forward, down, and true
		m_bAntlersDown = true;
	}else if(status == -1){
		m_cAntlers->Set(DoubleSolenoid::kReverse);	//-1 is reverse, up, and false
		m_bAntlersDown = false;
	}else{
		m_cAntlers->Set(DoubleSolenoid::kOff);		//0 is off/idle. Should maintain current position
	}
}
