#include "DriveStraightGyro.h"
#include "math.h"

// Used be constructed with (300,0.05,1,0,0,0)
DriveStraightGyro::DriveStraightGyro(const char *name): PIDCommand(name,1,0,0){
	Requires(CommandBase::chassis);
	this->chassis = CommandBase::chassis;
	moveSpeed = 0;
	goalTime = 0;
	GetPIDController()->Disable();
	chassis->gyro->InitGyro();
}

void DriveStraightGyro::SetGoal(double time, double speed) {
	goalTime=time;
	moveSpeed=speed;
	GetPIDController()->SetSetpoint(0);
}

// Called just before this Command runs the first time
void DriveStraightGyro::Initialize() {
	std::cerr << "Entering Gyro mode" << std::endl;
	GetPIDController()->SetSetpoint(0);
	chassis->gyro->Reset();
	SetGoal(0,0);
	GetPIDController()->Enable();
	std::cerr << "DriveStraightGyro initialized" << std::endl;
}

// Called repeatedly when this Command is scheduled to run
void DriveStraightGyro::Execute() {
	moveSpeed = 0.5 * (CommandBase::oi->stickL->GetY()+CommandBase::oi->stickR->GetY());
	//continuously corrects turning while driving straight
}

// Make this return true when this Command no longer needs to run execute()
bool DriveStraightGyro::IsFinished(){
	if(CommandBase::oi->rightPrecision->Get()) return false;
	else return true;
}

double DriveStraightGyro::ReturnPIDInput(){
	double ret = chassis->gyro->GetAngle();
	return ret / 20.0;
}

void DriveStraightGyro::UsePIDOutput(double outputAngle){
	//proportionality constant causes opposite turning to counteract
	//current turning and speed based off of above motor(s)
	std::cerr << "Gyro: " << outputAngle << std::endl;
	if(false)
	{
		chassis->m_drive.TankDrive(moveSpeed-outputAngle,moveSpeed+outputAngle);
	}
	else
	{
		chassis->m_drive.TankDrive(moveSpeed+outputAngle,moveSpeed-outputAngle);
	}

	/*
	if(timer.Get()<=goalTime){

	}
	*/
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
