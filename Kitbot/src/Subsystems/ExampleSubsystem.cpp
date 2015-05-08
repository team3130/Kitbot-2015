#include "ExampleSubsystem.h"
#include "../RobotMap.h"
#include "../Commands/ExampleCommand.h"

ExampleSubsystem::ExampleSubsystem()
	: PIDSubsystem("ExampleSubsystem", 0.05, 0.00, 0.15)
	, m_bIsUsingGyro(false)
	, m_bIsUsingEncoders(false)
	, m_bSquaredDrive(false)
	, moveSpeed(0)
	, m_drive(LEFTFRONTMOTOR,LEFTBACKMOTOR,RIGHTFRONTMOTOR,RIGHTBACKMOTOR)
{
	m_drive.SetSafetyEnabled(false);
	m_drive.SetInvertedMotor(m_drive.kRearLeftMotor, true);
	m_drive.SetInvertedMotor(m_drive.kRearRightMotor, true);
	m_drive.SetInvertedMotor(m_drive.kFrontLeftMotor, true);
	m_drive.SetInvertedMotor(m_drive.kFrontRightMotor, true);

	m_cEncoderL = new Encoder(DRIVE_ENCODERL_A,DRIVE_ENCODERL_B);
	m_cEncoderR = new Encoder(DRIVE_ENCODERR_A,DRIVE_ENCODERR_B);
	ResetEncoders();
	gyro  = new Gyro(C_GYRO);
	GetPIDController()->Disable();
	gyro->InitGyro();
	gyro->Reset();
}

ExampleSubsystem::~ExampleSubsystem()
{
	delete gyro;
	delete m_cEncoderL;
	delete m_cEncoderR;
}

void ExampleSubsystem::InitDefaultCommand()
{
	SetDefaultCommand(new ExampleCommand());
}

void ExampleSubsystem::Drive(double move, double turn, bool quad)
{
	m_drive.ArcadeDrive(move, turn, quad);
	if(m_bIsUsingGyro || m_bIsUsingEncoders)
	{
		m_bIsUsingGyro = false;
		m_bIsUsingEncoders = false;
		GetPIDController()->Disable();
	}
}

void ExampleSubsystem::HoldAngle(double angle)
{
	m_bIsUsingGyro = false;
	m_bIsUsingEncoders = true;
	GetPIDController()->SetSetpoint(GetAngle() + angle);
	GetPIDController()->Enable();
}

void ExampleSubsystem::TurnAngle(double angle)
{
	m_bIsUsingGyro = true;
	m_bIsUsingEncoders = false;
	GetPIDController()->SetSetpoint(GetAngle() + angle);
	GetPIDController()->Enable();
}

void ExampleSubsystem::ReleaseAngle()
{
	GetPIDController()->Disable();
	m_bIsUsingGyro=false;
	m_bIsUsingEncoders = false;
}


void ExampleSubsystem::GyroDrive(double move, bool squaredInputs)
{
	m_bSquaredDrive = squaredInputs;
	moveSpeed = move;
	if(!m_bIsUsingGyro)
	{
		m_bIsUsingGyro = true;
		m_bIsUsingEncoders = false;
		GetPIDController()->Enable();
	}
}

void ExampleSubsystem::EncodersDrive(double move, bool squaredInputs)
{
	m_bSquaredDrive = squaredInputs;
	moveSpeed = move;
	if(!m_bIsUsingEncoders)
	{
		m_bIsUsingEncoders = true;
		m_bIsUsingGyro = false;
		GetPIDController()->Enable();
	}
}

double ExampleSubsystem::GetAngle()
{
	if(m_bIsUsingEncoders) {
		return ( m_cEncoderL->GetDistance() - m_cEncoderR->GetDistance() ) * -180 / (ROBOT_GAUGE * M_PI);
		/*
		 *  Angle is 180 degrees times encoder difference over Pi * the distance between the wheels
		 *	Made from geometry and relation between angle fraction and arc fraction with semicircles.
		 *  Negative because our encoders connected backwards
		 */
	}
	else {
		return gyro->GetAngle();
	}
}

double ExampleSubsystem::ReturnPIDInput()
{
	return GetAngle();
}

void ExampleSubsystem::UsePIDOutput(double bias)
{
	const double speedLimit = 0.65;
	SmartDashboard::PutNumber("Turn PID bias",bias);
	if(bias >  speedLimit) bias = speedLimit;
	if(bias < -speedLimit) bias = -speedLimit;
	double speed_L = moveSpeed-bias;
	double speed_R = moveSpeed+bias;
	m_drive.TankDrive(speed_L, speed_R, m_bSquaredDrive);
}

double ExampleSubsystem::GetDistance()
{
	return ( m_cEncoderL->GetDistance() + m_cEncoderR->GetDistance() ) / -2.0;
}

void ExampleSubsystem::ResetEncoders()
{
	m_cEncoderL->Reset();
	m_cEncoderR->Reset();
	m_cEncoderL->SetDistancePerPulse(WHEEL_DIAMATER * M_PI / 128); // 70/468 = 0.15
	m_cEncoderR->SetDistancePerPulse(WHEEL_DIAMATER * M_PI /256); // 70/937 = 0.07
}
