#include "Bincher.h"
#include "../RobotMap.h"
#include "../Commands/ControlBincher.h"

Bincher::Bincher() : Subsystem("Bincher")
{
	m_cBincher = new Solenoid(COMPRESSOR, BINCHER);
	m_bIsPinching = false;
}

Bincher::~Bincher(){
	delete m_cBincher;
}

void Bincher::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new ControlBincher());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void Bincher::SetPinch(bool isPinch)
{
	m_cBincher->Set(isPinch);
}
