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
	m_dRateDifference = 0;
	m_dlifterPosition = 0;
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

void Lifter::SetDirection(int direction)
{
	float speed;
	if(direction == 1){
		speed = 1;
	}else if(direction == -1){
		speed = -1;
	}else{
		speed = 0;
	}
	//TODO: Change orientation later depending on actual motor orientation
	m_cLiftMotorL->SetSpeed(speed);
	m_cLiftMotorR->SetSpeed(speed);
}
