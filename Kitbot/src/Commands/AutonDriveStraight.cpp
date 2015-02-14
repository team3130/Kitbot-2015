#include "AutonDriveStraight.h"
#include <math.h>

// Used be constructed with (300,0.05,1,0,0,0)
AutonDriveStraight::AutonDriveStraight()
	: PIDCommand(1/20, 0, 0)
{
	GetPIDController()->Disable();
	Requires(CommandBase::chassis);
	SmartDashboard::PutNumber("Straight PID P",0.1);
	SmartDashboard::PutNumber("Straight PID I",0);
	SmartDashboard::PutNumber("Straight PID D",0);
}

void AutonDriveStraight::SetGoal(double dist, double thresh, double timeToWait, double ispeed) {
	goal=dist;
	threshold=thresh;
	confirmTime=timeToWait;
	speed = ispeed;
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
	isConfirming = false;
	CommandBase::chassis->HoldAngle(0.0);
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
	}
	return false;
}

double AutonDriveStraight::ReturnPIDInput(){

	double totalDistance = 0;
	int nEncoders = 0;

		totalDistance += CommandBase::chassis->m_cEncoderL->GetDistance();
		nEncoders++;

		totalDistance += CommandBase::chassis->m_cEncoderR->GetDistance();
		nEncoders++;

	if(nEncoders>0){
		return (totalDistance/nEncoders);
	}else{
		return 0;
	}
}

void AutonDriveStraight::UsePIDOutput(double output){
	if(output>1)output=1;
	if(output<-1)output=-1;
	CommandBase::chassis->GyroDrive(speed*output);
}

// Called once after isFinished returns true
void AutonDriveStraight::End() {
	GetPIDController()->Disable();
	CommandBase::chassis->GyroDrive(0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonDriveStraight::Interrupted() {
	End();
}
