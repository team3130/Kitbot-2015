#include "DriveStraightGyro.h"

// Used be constructed with (300,0.05,1,0,0,0)
DriveStraightGyro::DriveStraightGyro(const char *name)
	: PIDCommand(name, 1/20, 0, 0)
	, moveSpeed(0)
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
	GetPIDController()->Enable();
}

// Called repeatedly when this Command is scheduled to run
void DriveStraightGyro::Execute() {
	moveSpeed = 0.5 * (CommandBase::oi->stickL->GetY()+CommandBase::oi->stickR->GetY());
}

// Make this return true when this Command no longer needs to run execute()
bool DriveStraightGyro::IsFinished(){
	return ! CommandBase::oi->rightPrecision->Get();
}

double DriveStraightGyro::ReturnPIDInput(){
	return CommandBase::chassis->gyro->GetAngle();
}

void DriveStraightGyro::UsePIDOutput(double outputAngle){
	CommandBase::chassis->m_drive.TankDrive(moveSpeed+outputAngle,moveSpeed-outputAngle);
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
