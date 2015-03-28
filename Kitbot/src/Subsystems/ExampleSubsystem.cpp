#include "ExampleSubsystem.h"
#include "../RobotMap.h"
#include "../Commands/ExampleCommand.h"

ExampleSubsystem::ExampleSubsystem()
	: PIDSubsystem("ExampleSubsystem", 0.05, 0.00, 0.15)
	, m_bIsUsingGyro(false)
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
	ResetEncoders();
	gyro  = new Gyro(C_GYRO);
	GetPIDController()->Disable();
	gyro->InitGyro();
	gyro->Reset();
	SmartDashboard::PutNumber("TurnPID_P",0.03);
	SmartDashboard::PutNumber("TurnPID_I",0.00);
	SmartDashboard::PutNumber("TurnPID_D",0.00);
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
	GetPIDController()->SetSetpoint(GetAngle() + angle);
	GetPIDController()->Enable();
	m_bIsUsingGyro = true;
}

void ExampleSubsystem::GyroDrive(double move, bool squaredInputs)
{
	m_bSquaredDrive = squaredInputs;
	moveSpeed = move;
	if(!m_bIsUsingGyro)
	{
		m_bIsUsingGyro = true;
	/*	GetPIDController()->SetPID(
				SmartDashboard::GetNumber("TurnPID_P",0.0),
				SmartDashboard::GetNumber("TurnPID_I",0.00),
				SmartDashboard::GetNumber("TurnPID_D",0.0)
				); */
		GetPIDController()->Enable();
	}
	SmartDashboard::PutNumber("Check PID P",GetPIDController()->GetP());
}

double ExampleSubsystem::GetAngle()
{
	return ( m_cEncoderL->GetDistance() - m_cEncoderR->GetDistance() ) * -180 / (ROBOT_GAUGE * M_PI);
	/*
	 *  Angle is 180 degrees times encoder difference over Pi * the distance between the wheels
	 *	Made from geometry and relation between angle fraction and arc fraction with semicircles.
	 *  Negative because our encoders connected backwards
	 */
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
	m_cEncoderL->SetDistancePerPulse(WHEEL_DIAMATER * M_PI / Preferences::GetInstance()->GetInt("Encoder_Left", 128)); // 70/468 = 0.15
	m_cEncoderR->SetDistancePerPulse(WHEEL_DIAMATER * M_PI / Preferences::GetInstance()->GetInt("Encoder_Right", 256)); // 70/937 = 0.07
}
