#include "Lifter.h"
#include "../RobotMap.h"
#include "../Commands/ControlLifter.h"

Lifter::Lifter()
	: Subsystem("Lifter")
{
	m_cLiftMotorL = new Talon(LIFTERL);
	m_cLiftMotorR = new Talon(LIFTERR);
	m_cLimitSwitch = new DigitalInput(LIFTERSWITCH);
	m_cEncoderL = new Encoder(ENCODERL_A, ENCODERL_B, false);
	m_cEncoderR = new Encoder(ENCODERR_A, ENCODERR_B, false);
	m_dLifterPosition = 0;
}

Lifter::~Lifter(){
	delete m_cEncoderL;
	delete m_cEncoderR;
	delete m_cLimitSwitch;
	delete m_cLiftMotorL;
	delete m_cLiftMotorR;
}

void Lifter::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new ControlLifter());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

double Lifter::getLeftSpeed(){
	return m_cLiftMotorL->Get();
}

double Lifter::getRightSpeed(){
	return m_cLiftMotorR->Get();
}
//Keeps motors level
void Lifter::Balance(float fDirection)
{
	// Get fraction from difference in encoder values. When less than 1 left is higher,
	// when greater than 1 right is higher.
	double dRateDifference = 1-(1/(m_cEncoderL->Get()-m_cEncoderR->Get()));
	if(fDirection > 0)
	{
		m_cLiftMotorL->SetSpeed(fDirection*dRateDifference);
		m_cLiftMotorR->SetSpeed(fDirection/dRateDifference);
	}
	else if(not m_cLimitSwitch->Get())
	{
		m_cLiftMotorL->SetSpeed(fDirection/dRateDifference);
		m_cLiftMotorR->SetSpeed(fDirection*dRateDifference);
	}
	//reset enocders when lifter is at the bottom
	if(m_cLimitSwitch->Get()){
		m_cEncoderL->Reset();
		m_cEncoderR->Reset();
	}
}
