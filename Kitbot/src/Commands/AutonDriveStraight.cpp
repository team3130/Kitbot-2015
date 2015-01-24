#include "AutonDriveStraight.h"
#include <math.h>

// Used be constructed with (300,0.05,1,0,0,0)
AutonDriveStraight::AutonDriveStraight()
	: PIDCommand(1/20, 0, 0)
	, moveSpeed(0)
	, moveTurn(0)
	, gyroMode(false)
{
	GetPIDController()->Disable();
	Requires(CommandBase::chassis);
	m_nDrivePowerL = 0;
	m_nDrivePowerR = 0;
	m_nTimer = 1;
	m_bExecute = false;
	CommandBase::chassis->gyro->InitGyro();
	CommandBase::chassis->gyro->Reset();
}

// Called just before this Command runs the first time
void AutonDriveStraight::Initialize() {
	double currentAngle = CommandBase::chassis->gyro->GetAngle();
	GetPIDController()->SetSetpoint(currentAngle);
	//GetPIDController()->Enable();
}

// Called repeatedly when this Command is scheduled to run
void AutonDriveStraight::Execute() {
	if(m_bExecute){
		CommandBase::chassis->m_drive.TankDrive(m_nDrivePowerL, m_nDrivePowerR);
		m_nTimer -= 1;	//Causes driving to stop after Timer runs down
	}
}
// Make this return true when this Command no longer needs to run execute()
bool AutonDriveStraight::IsFinished(){
	if(m_nTimer <= 0){
		m_bExecute=false;
		return true;
	}
	else{return false;}
}

double AutonDriveStraight::ReturnPIDInput(){
	double ret = CommandBase::chassis->gyro->GetAngle();
	double rot = CommandBase::chassis->gyro->GetRate();
	SmartDashboard::PutNumber("Gyro Current Angle: ", ret);
	SmartDashboard::PutNumber("Gyro Rotation Rate: ", rot);
	return ret;
}

void AutonDriveStraight::UsePIDOutput(double outputAngle){
	if(gyroMode)
	{
		CommandBase::chassis->m_drive.TankDrive(m_nDrivePowerL-outputAngle,m_nDrivePowerR+outputAngle);
	}
	else
	{
		CommandBase::chassis->m_drive.TankDrive(m_nDrivePowerL, m_nDrivePowerR);
	}
}

// Called once after isFinished returns true
void AutonDriveStraight::End() {
	GetPIDController()->Disable();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonDriveStraight::Interrupted() {
	End();
}
