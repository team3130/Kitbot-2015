#include "DriveStraightGyro.h"
#include "math.h"

// Used be constructed with (300,0.05,1,0,0,0)
DriveStraightGyro::DriveStraightGyro(const char *name): PIDCommand(name,0.3,0,0){
	Requires(CommandBase::chassis);
	this->chassis = CommandBase::chassis;
	moveSpeed = 0.5;
	goalTime = 0;
	//SetGoal(2,0.5);
}

void DriveStraightGyro::SetGoal(double time, double speed) {
	goalTime=time;
	moveSpeed=speed;
	GetPIDController()->SetSetpoint(0);
}

// Called just before this Command runs the first time
void DriveStraightGyro::Initialize() {
	//GetPIDController()->SetPID(np,ni,nd);
	GetPIDController()->SetSetpoint(0);
	//chassis->InitEncoders();
	//chassis->DumbRobot();
	timer.Reset();
	timer.Start();
	chassis->gyro->InitGyro();
	chassis->gyro->Reset();
	SetGoal(0,0);
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
	return chassis->gyro->GetAngle();
}

void DriveStraightGyro::UsePIDOutput(double outputAngle){
	//proportionality constant causes opposite turning to counteract
	//current turning and speed based off of above motor(s)
	chassis->m_drive.Drive(moveSpeed,-outputAngle);

	/*
	if(timer.Get()<=goalTime){

	}
	*/
}

// Called once after isFinished returns true
void DriveStraightGyro::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveStraightGyro::Interrupted() {
	End();
}
