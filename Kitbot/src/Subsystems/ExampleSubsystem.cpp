#include "ExampleSubsystem.h"
#include "../RobotMap.h"
#include "../Commands/ExampleCommand.h"

ExampleSubsystem::ExampleSubsystem()
	: PIDSubsystem("ExampleSubsystem", 0.0, 0.0, 0.0)
	, m_bSquaredDrive(true)
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
	m_cEncoderL->SetDistancePerPulse(24.0/160);
	m_cEncoderR->SetDistancePerPulse(24.0/320);
	gyro  = new Gyro(C_GYRO);
	m_bIsUsingGyro = true;
	GetPIDController()->Disable();
	gyro->InitGyro();
	gyro->Reset();
	SmartDashboard::PutNumber("DB/Slider 0", Preferences::GetInstance()->GetDouble("Gyro_PID_P")/0.1);
	SmartDashboard::PutNumber("DB/Slider 1", Preferences::GetInstance()->GetDouble("Gyro_PID_I")/0.1);
	SmartDashboard::PutNumber("DB/Slider 2", Preferences::GetInstance()->GetDouble("Gyro_PID_D")/0.1);
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
	if(m_bIsUsingGyro)
	{
		m_bIsUsingGyro = false;
		GetPIDController()->Disable();
	}
}

void ExampleSubsystem::HoldAngle(double angle)
{
	np = SmartDashboard::GetNumber("DB/Slider 0") * 0.1;
	ni = SmartDashboard::GetNumber("DB/Slider 1") * 0.1;
	nd = SmartDashboard::GetNumber("DB/Slider 2") * 0.1;
	GetPIDController()->SetPID(np,ni,nd);
	GetPIDController()->SetSetpoint(GetAngle() + angle);
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

double ExampleSubsystem::GetDistance()
{
	return ( m_cEncoderL->GetDistance() + m_cEncoderR->GetDistance() ) / 2.0;
}
