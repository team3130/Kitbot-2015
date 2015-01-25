#include "ExampleSubsystem.h"
#include "../RobotMap.h"
#include "../Commands/DriveStraightGyro.h"
#include "../Commands/GyroTest.h"

ExampleSubsystem::ExampleSubsystem()
	: Subsystem("ExampleSubsystem")
	, m_drive(LEFTMOTOR,RIGHTMOTOR)
{
	m_drive.SetSafetyEnabled(false);
	m_drive.SetInvertedMotor(m_drive.kRearLeftMotor, true);
	m_drive.SetInvertedMotor(m_drive.kRearRightMotor, true);
	m_cEncoderL = new Encoder(DRIVE_ENCODERL_A,DRIVE_ENCODERL_B);
	m_cEncoderR = new Encoder(DRIVE_ENCODERR_A,DRIVE_ENCODERR_B);
	m_bIsUsingGyro = false;
	gyro  = new Gyro(C_GYRO);
}

ExampleSubsystem::~ExampleSubsystem()
{
	delete gyro;
	delete m_cEncoderL;
	delete m_cEncoderR;
}

void ExampleSubsystem::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new DriveStraightGyro("Default drive"));
	//SetDefaultCommand(new GyroTest());
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
