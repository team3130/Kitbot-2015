#include <Commands/ControlAntlerMoose.h>
#include "AntlerMoose.h"
#include "../RobotMap.h"

AntlerMoose::AntlerMoose()
	: Subsystem("AntlerMoose")
{
	m_cLeftAntler = new DoubleSolenoid(COMPRESSOR, LEFTANTLERA, LEFTANTLERB);
	m_cRightAntler = new DoubleSolenoid(COMPRESSOR, RIGHTANTLERA, RIGHTANTLERB);
	m_bLeftAntlerDown = false;
	m_bRightAntlerDown = false;
	m_cLeftAntler->Set(DoubleSolenoid::kOff);	//initially idles
	m_cRightAntler->Set(DoubleSolenoid::kOff);
}

AntlerMoose::~AntlerMoose(){
	delete m_cLeftAntler;
	delete m_cRightAntler;
}

void AntlerMoose::InitDefaultCommand()
{
	SetDefaultCommand(new ControlAntlerMoose());
}

void AntlerMoose::ControlLeftAntler(DoubleSolenoid::Value leftStatus)
{
	if(leftStatus == DoubleSolenoid::kForward){
		m_bLeftAntlerDown = true;		//forward is down and true
	}else if(leftStatus == DoubleSolenoid::kReverse){
		m_bLeftAntlerDown = false;		//reverse is up and false
	}
	//kOff means that status will not change and should instead idle
	m_cLeftAntler->Set(leftStatus);
}

void AntlerMoose::ControlRightAntler(DoubleSolenoid::Value rightStatus)
{
	if(rightStatus == DoubleSolenoid::kForward){
		m_bRightAntlerDown = true;		//forward is down and true
	}else if(rightStatus == DoubleSolenoid::kReverse){
		m_bRightAntlerDown = false;		//reverse is up and false
	}
	//kOff means that status will not change and should instead idle
	m_cRightAntler->Set(rightStatus);
}
