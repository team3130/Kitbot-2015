#include "BinIntake.h"
#include "../RobotMap.h"
#include "../Commands/ControlBinLifter.h"

BinIntake::BinIntake()
	: Subsystem("BinIntake")
{
		m_cBinRotateMotor = new Talon(BINROTATOR);
		m_cBinLiftMotor = new Talon(BINLIFTER);

}

BinIntake::~BinIntake()
{
	delete m_cBinRotateMotor;

}
void BinIntake::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new ControlBinLifter());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void BinIntake::Spin()
{

}
