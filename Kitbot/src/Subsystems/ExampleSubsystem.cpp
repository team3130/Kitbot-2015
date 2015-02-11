#include "ExampleSubsystem.h"
#include "../RobotMap.h"
#include "../Commands/ExampleCommand.h"

ExampleSubsystem::ExampleSubsystem()
	: PIDSubsystem("ExampleSubsystem",0.07,0.0,0.2)
	, m_bSquaredDrive(true)
	, moveSpeed(0)
	, m_drive(LEFTFRONTMOTOR,LEFTBACKMOTOR,RIGHTFRONTMOTOR,RIGHTBACKMOTOR)
{
	m_drive.SetSafetyEnabled(false);
	m_drive.SetInvertedMotor(m_drive.kRearLeftMotor, true);
	m_drive.SetInvertedMotor(m_drive.kRearRightMotor, true);
	m_drive.SetInvertedMotor(m_drive.kFrontLeftMotor, true);
	m_drive.SetInvertedMotor(m_drive.kFrontRightMotor, true);

	m_cEncoderUL = new Encoder(DRIVE_ENCODERUL_A,DRIVE_ENCODERUL_B);
	m_cEncoderUR = new Encoder(DRIVE_ENCODERUR_A,DRIVE_ENCODERUR_B);
	m_cEncoderLL = new Encoder(DRIVE_ENCODERLL_A,DRIVE_ENCODERLL_B);
	m_cEncoderLR = new Encoder(DRIVE_ENCODERLR_A,DRIVE_ENCODERLR_B);
	gyro  = new Gyro(C_GYRO);
	m_bIsUsingGyro = true;
	GetPIDController()->Disable();
	gyro->InitGyro();
	gyro->Reset();
}

ExampleSubsystem::~ExampleSubsystem()
{
	delete gyro;
	delete m_cEncoderUL;
	delete m_cEncoderUR;
	delete m_cEncoderLL;
	delete m_cEncoderLR;
}

void ExampleSubsystem::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new ExampleCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void ExampleSubsystem::Drive(double move, double turn, bool quad)
{
	m_drive.ArcadeDrive(move, turn, quad);
	if(m_bIsUsingGyro)
	{
		m_bIsUsingGyro = false;
		GetPIDController()->Disable();
	}
}

void ExampleSubsystem::HoldAngle(double angle)
{
	GetPIDController()->SetSetpoint(angle);
	GetPIDController()->Enable();
}

void ExampleSubsystem::GyroDrive(double move, bool squaredInputs)
{
	m_bSquaredDrive = squaredInputs;
	moveSpeed = move;
	if(!m_bIsUsingGyro)
	{
		m_bIsUsingGyro = true;
		GetPIDController()->Enable();
	}
}

double ExampleSubsystem::ReturnPIDInput()
{
	return gyro->GetAngle();
}

void ExampleSubsystem::UsePIDOutput(double outputAngle)
{
	m_drive.TankDrive(moveSpeed-outputAngle, moveSpeed+outputAngle, m_bSquaredDrive);
}
