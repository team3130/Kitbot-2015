#include "Lifter.h"
#include "../RobotMap.h"
#include "../Commands/ControlLifter.h"

Lifter::Lifter()
	: Subsystem("Lifter")
{
	m_cLiftMotorL = new SpeedController(LIFTERL);
	m_cLiftMotorR = new SpeedController(LIFTERR);
	m_cEncoderL = new Encoder(ENCODERL);
	m_cEncoderR = new Encoder(ENCODERR);
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

void Lifter::Move(GenericHID *gamepad)
{
	//placeholder values
	m_cLiftMotorL.SpeedController::Set(0);
	m_cLiftMotorR.SpeedController::Set(0);
}
