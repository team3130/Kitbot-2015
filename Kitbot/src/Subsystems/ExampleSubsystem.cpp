#include "ExampleSubsystem.h"
#include "../RobotMap.h"
#include "../Commands/ExampleCommand.h"

ExampleSubsystem::ExampleSubsystem()
	: Subsystem("ExampleSubsystem")
	, m_drive(LEFTMOTOR,RIGHTMOTOR)
{
	m_drive.SetSafetyEnabled(false);
	m_bIsUsingGyro = false;
	gyro  = new Gyro(C_GYRO);
	//m_drive.SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);
	//m_drive.SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
}

ExampleSubsystem::~ExampleSubsystem()
{
	delete gyro;
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

bool ExampleSubsystem::CanUseGyro()
{
 return m_bIsUsingGyro;
}
