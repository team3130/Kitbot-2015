#include "AntlerMoose.h"
#include "../RobotMap.h"
#include "../Commands/ControlAntlerMoose.h"

AntlerMoose::AntlerMoose()
	: Subsystem("AntlerMoose")
{
	m_cAntlerMooseLock = new DoubleSolenoid(COMPRESSOR, MOOSELOCK, MOOSELOCK2);
	m_bActivated = false;
}

AntlerMoose::~AntlerMoose(){
	delete m_cAntlerMooseLock;
}

void AntlerMoose::InitDefaultCommand()
{
	SetDefaultCommand(new ControlAntlerMoose());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void AntlerMoose::MoveAntlerLock(bool status)
{
	if(status){
		m_cAntlerMooseLock->Set(DoubleSolenoid::kForward);
	}else{
		m_cAntlerMooseLock->Set(DoubleSolenoid::kReverse);

}
}
