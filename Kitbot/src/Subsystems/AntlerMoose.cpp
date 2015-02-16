#include <Commands/ControlAntlerMoose.h>
#include "AntlerMoose.h"
#include "../RobotMap.h"

AntlerMoose::AntlerMoose()
	: Subsystem("AntlerMoose")
{
	m_cAntlers = new DoubleSolenoid(COMPRESSOR, LEFTANTLER, RIGHTANTLER);
	//m_cLeftAntler = new Solenoid(COMPRESSOR, LEFTANTLER);
	//m_cRightAntler = new Solenoid(COMPRESSOR, RIGHTANTLER);
	//false is considered to be up. TODO: Change if orientation does
	m_bLeftDown = false;
	m_bRightDown = false;
}

AntlerMoose::~AntlerMoose(){
	delete m_cAntlers;
	//delete m_cLeftAntler;
	//delete m_cRightAntler;
}

void AntlerMoose::InitDefaultCommand()
{
	SetDefaultCommand(new ControlAntlerMoose());
}

void AntlerMoose::ControlAntlers(int status)
{
	if(status == 1){
		m_cAntlers->Set(DoubleSolenoid::kForward);
	}else if(status == -1){
		m_cAntlers->Set(DoubleSolenoid::kReverse);
	}else{
		m_cAntlers->Set(DoubleSolenoid::kOff);
	}
}

void AntlerMoose::ControlLeftAntler(bool downLeft)
{
	m_bLeftDown = downLeft;
	m_cLeftAntler->Set(downLeft);
}

void AntlerMoose::ControlRightAntler(bool downRight)
{
	m_bRightDown = downRight;
	m_cRightAntler->Set(downRight);
}
