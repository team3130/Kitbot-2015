#include <Commands/ControlAntlerMoose.h>
#include "AntlerMoose.h"
#include "../RobotMap.h"

AntlerMoose::AntlerMoose()
	: Subsystem("AntlerMoose")
{
	m_cLeftAntler = new Solenoid(COMPRESSOR, LEFTANTLER);
	m_cRightAntler = new Solenoid(COMPRESSOR, RIGHTANTLER);
	m_bLeftAntlerDown = false;
	m_bRightAntlerDown = false;
	m_cLeftAntler->Set(true);	//initially idles
	m_cRightAntler->Set(true);
}

AntlerMoose::~AntlerMoose(){
	delete m_cLeftAntler;
	delete m_cRightAntler;
}

void AntlerMoose::InitDefaultCommand()
{
	SetDefaultCommand(new ControlAntlerMoose());
}

void AntlerMoose::ControlLeftAntler(bool Up)
{
	m_cLeftAntler->Set(Up);
	m_bLeftAntlerDown = Up;
}

void AntlerMoose::ControlRightAntler(bool Up)
{
	m_cRightAntler->Set(Up);
	m_bRightAntlerDown = Up;
}
