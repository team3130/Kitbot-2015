#include "DriveStraightGyro.h"
#include <math.h>

// Used be constructed with (300,0.05,1,0,0,0)
DriveStraightGyro::DriveStraightGyro(const char *name): PIDCommand(name,  0  ,  0  ,  0  ){
	Requires(CommandBase::chassis);
	prefs = Preferences::GetInstance();
	moveSpeed = 0;
	moveTurn = 0;
	gyroMode = false;
	GetPIDController()->Disable();
	Requires(CommandBase::chassis);
	CommandBase::chassis->gyro->InitGyro();
	CommandBase::chassis->gyro->Reset();
	prefs->PutDouble("GyroPIDP",0.07);
	prefs->PutDouble("GyroPIDI",0);
	prefs->PutDouble("GyroPIDD",0.2);
	SmartDashboard::PutNumber("DB/Slider 0", 0.07 / 0.1 );
	SmartDashboard::PutNumber("DB/Slider 1", 0.0 / 0.1 );
	SmartDashboard::PutNumber("DB/Slider 2", 0.2 / 0.1 );

}

// Called just before this Command runs the first time
void DriveStraightGyro::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DriveStraightGyro::Execute() {
	//np = prefs->GetDouble("GyroPIDP");
	//ni = prefs->GetDouble("GyroPIDI");
	//nd = prefs->GetDouble("GyroPIDD");
	np = SmartDashboard::GetNumber("DB/Slider 0") * 0.1;
	ni = SmartDashboard::GetNumber("DB/Slider 1") * 0.1;
	nd = SmartDashboard::GetNumber("DB/Slider 2") * 0.1;
	GetPIDController()->SetPID(np,ni,nd);
	//prefs->Save(); //commented out for safety issues with constant rewriting of flash memory

	moveSpeed = CommandBase::oi->stickL->GetY();
	moveTurn =  CommandBase::oi->stickR->GetX();
	double turnLimit = CommandBase::oi->stickR->GetZ();

	if(fabs(moveTurn) > turnLimit)
	{
		if(gyroMode) {
			gyroMode = false;
			GetPIDController()->Disable();
		}
		CommandBase::chassis->m_drive.ArcadeDrive(moveSpeed,moveTurn);
	}
	else
	{
		if(!gyroMode) {
			gyroMode = true;
			double currentAngle = CommandBase::chassis->gyro->GetAngle();
			GetPIDController()->SetSetpoint(currentAngle);
			GetPIDController()->Enable();
		}
	}
}

// Make this return true when this Command no longer needs to run execute()
bool DriveStraightGyro::IsFinished(){
	return false; //! CommandBase::oi->rightPrecision->Get();
}

double DriveStraightGyro::ReturnPIDInput(){
	double ret = CommandBase::chassis->gyro->GetAngle();
	double rot = CommandBase::chassis->gyro->GetRate();
	SmartDashboard::PutNumber("Gyro Current Angle: ", ret);
	SmartDashboard::PutNumber("Gyro Rotation Rate: ", rot);
	return ret;
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
