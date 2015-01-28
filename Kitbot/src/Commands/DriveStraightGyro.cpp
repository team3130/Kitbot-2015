#include "DriveStraightGyro.h"
#include <math.h>

// Used be constructed with (300,0.05,1,0,0,0)
DriveStraightGyro::DriveStraightGyro(const char *name)
	: PIDCommand(name, 1/20, 0, 0)
	, moveSpeed(0)
	, moveTurn(0)
	, gyroMode(false)
{
	GetPIDController()->Disable();
	Requires(CommandBase::chassis);
	CommandBase::chassis->gyro->InitGyro();
	CommandBase::chassis->gyro->Reset();
}

// Called just before this Command runs the first time
void DriveStraightGyro::Initialize() {
	double currentAngle = CommandBase::chassis->gyro->GetAngle();
	GetPIDController()->SetSetpoint(currentAngle);
	//GetPIDController()->Enable();
}

// Called repeatedly when this Command is scheduled to run
void DriveStraightGyro::Execute() {
	moveSpeed = CommandBase::oi->stickL->GetY();
	moveTurn = CommandBase::oi->stickR->GetX();

	CommandBase::chassis->m_drive.ArcadeDrive(moveSpeed,moveTurn);
	if(fabs(moveTurn)>0.2)
	{
		gyroMode = false;
	}
	else
	{
		gyroMode = true;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool DriveStraightGyro::IsFinished(){
	return false; //! CommandBase::oi->rightPrecision->Get();
}

double DriveStraightGyro::ReturnPIDInput(){
	double dRet = CommandBase::chassis->gyro->GetAngle();
	double dRot = CommandBase::chassis->gyro->GetRate();
	SmartDashboard::PutNumber("Gyro Current Angle: ", dRet);
	SmartDashboard::PutNumber("Gyro Rotation rate: ", dRot);
	return dRet;
}

void DriveStraightGyro::UsePIDOutput(double outputAngle){
	if(gyroMode)
	{
		CommandBase::chassis->m_drive.TankDrive(moveSpeed-outputAngle,moveSpeed+outputAngle);
	}
	else
	{
		CommandBase::chassis->m_drive.ArcadeDrive(moveSpeed,moveTurn);
	}
}

// Called once after isFinished returns true
void DriveStraightGyro::End() {
	GetPIDController()->Disable();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveStraightGyro::Interrupted() {
	End();
}
