#include "ExampleSubsystem.h"
#include "../RobotMap.h"
#include "../Commands/ExampleCommand.h"

ExampleSubsystem::ExampleSubsystem()
	: Subsystem("ExampleSubsystem")
	, m_drive(LEFTMOTOR,RIGHTMOTOR)
{

}

void ExampleSubsystem::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new ExampleCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void ExampleSubsystem::Drive(GenericHID *leftStick, GenericHID *rightStick, bool squaredInputs)
{
	m_drive.TankDrive(leftStick, rightStick, squaredInputs);
}
