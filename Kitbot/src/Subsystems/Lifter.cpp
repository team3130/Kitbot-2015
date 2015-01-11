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
	//Get fraction from difference in encoder values
	//fDirection ensures that difference will be same proportion for all axis values
	//Code will only do something if fDirection is not 0, aka stick is not neutral
	if(fDirection != 0){
		double dRateDifference;
		//prevents divide-by-zero errors in case of encoders at 0
		if((m_cEncoderL->Get()+m_cEncoderR->Get()) != 0){
			dRateDifference = fDirection*(m_cEncoderL->Get()-m_cEncoderR->Get())/(m_cEncoderL->Get()+m_cEncoderR->Get());
		}else{
			dRateDifference = 0;
		}

		//compensates for difference in motors using encoder rate difference
		if(fDirection > 0)
		{
			m_cLiftMotorL->SetSpeed(fDirection-dRateDifference);
			m_cLiftMotorR->SetSpeed(fDirection+dRateDifference);
		}
		else if(not m_cLimitSwitch->Get())
		{
			m_cLiftMotorL->SetSpeed(fDirection+dRateDifference);
			m_cLiftMotorR->SetSpeed(fDirection-dRateDifference);
		}
		//reset encoders when lifter is at the bottom
		if(m_cLimitSwitch->Get()){
			m_cEncoderL->Reset();
			m_cEncoderR->Reset();
		}
	}
}
