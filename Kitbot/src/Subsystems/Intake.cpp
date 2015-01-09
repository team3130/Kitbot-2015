#include "Intake.h"
#include "../RobotMap.h"
#include "../Commands/ExampleCommand.h"

Intake::Intake()
	: Subsystem("Intake")
	, m_drive(INTAKEL,INTAKER)
{

}

void Intake::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new ExampleCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Intake::Drive(GenericHID *leftStick, GenericHID *rightStick, bool squaredInputs)
{
	m_drive.TankDrive(leftStick, rightStick, squaredInputs);
}
