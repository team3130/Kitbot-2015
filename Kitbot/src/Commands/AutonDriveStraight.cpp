#include "AutonDriveStraight.h"
#include <math.h>

// Used be constructed with (300,0.05,1,0,0,0)
AutonDriveStraight::AutonDriveStraight()
	: PIDCommand(1/20, 0, 0)
	, m_bGyroPrep(true)
	, m_bGyroMode(false)
	, m_cGyroTimer()
{
	GetPIDController()->Disable();
	Requires(CommandBase::chassis);
	m_bExecute = false;
	SmartDashboard::PutNumber("Straight PID P",-3000);
	SmartDashboard::PutNumber("Straight PID I",0);
	SmartDashboard::PutNumber("Straight PID D",0);
}

void AutonDriveStraight::SetGoal(double dist, double thresh, double timeToWait, double ispeed) {
	goal=dist;
	threshold=thresh;
	confirmTime=timeToWait;
	speed = ispeed;
	if ( ispeed > 0.0 )
		dumbDriveTime /= ispeed;
	SmartDashboard::PutNumber(GetName()+"Straight Goal",goal);
	SmartDashboard::PutNumber(GetName()+"Straight Threshold",thresh);
	SmartDashboard::PutNumber(GetName()+"Straight Cooldown",timeToWait);
	SmartDashboard::PutNumber(GetName()+"Straight Speed",ispeed);
	GetPIDController()->SetSetpoint(goal);
	GetPIDController()->SetAbsoluteTolerance(threshold);
}

// Called just before this Command runs the first time
void AutonDriveStraight::Initialize() {
	double np=SmartDashboard::GetNumber("Straight PID P")/1000.;
	double ni=SmartDashboard::GetNumber("Straight PID I")/1000.;
	double nd=SmartDashboard::GetNumber("Straight PID D")/1000.;
	GetPIDController()->SetPID(np,ni,nd);
	GetPIDController()->SetSetpoint(goal);
	GetPIDController()->SetAbsoluteTolerance(threshold);
	keepAngle = CommandBase::chassis->gyro->GetAngle();
	timer.Reset();
	timer.Start();
}

// Called repeatedly when this Command is scheduled to run
void AutonDriveStraight::Execute() {
}
// Make this return true when this Command no longer needs to run execute()
bool AutonDriveStraight::IsFinished(){
	if(GetPIDController()->OnTarget()){
		if(!isConfirming) {
			isConfirming = true;
			timer.Reset();
			timer.Start();
		}
		return timer.Get() >= confirmTime;
	}else{
		isConfirming = false;
		timer.Stop();
		timer.Reset();
	}
	return false;
}

double AutonDriveStraight::ReturnPIDInput(){

	double totalDistance = 0;
	int nEncoders = 0;

		totalDistance += leftController->GetDistance();
		nEncoders++;

		totalDistance += rightController->GetDistance();
		nEncoders++;
	}
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
