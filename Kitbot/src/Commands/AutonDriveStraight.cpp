#include "AutonDriveStraight.h"
#include <math.h>

// Used be constructed with (300,0.05,1,0,0,0)
AutonDriveStraight::AutonDriveStraight()
	: PIDCommand(0.06, 0, 0.1)
	, speed(0)
	, goal(0)
	, threshold(0)
	, confirmTime(0)
	, dAngle(0)
{
	Requires(CommandBase::chassis);
}

void AutonDriveStraight::SetGoal(double dist, double thresh, double ispeed, double timeout, double angle) {
	goal = dist;
	threshold = thresh;
	speed = ispeed;
	confirmTime = timeout;
	dAngle = angle;
	GetPIDController()->SetSetpoint(goal);
	GetPIDController()->SetAbsoluteTolerance(threshold);
}

// Called just before this Command runs the first time
void AutonDriveStraight::Initialize() {
	GetPIDController()->Disable();
	GetPIDController()->SetSetpoint(goal);
	GetPIDController()->SetAbsoluteTolerance(threshold);
	CommandBase::chassis->ResetEncoders();
	CommandBase::chassis->HoldAngle(dAngle);
	GetPIDController()->Reset();
	GetPIDController()->Enable();
	timer.Reset();
	timer.Start();
}

// Called repeatedly when this Command is scheduled to run
void AutonDriveStraight::Execute() {
}

// Make this return true when this Command no longer needs to run execute()
bool AutonDriveStraight::IsFinished(){
	char message[64];
	if(GetPIDController()->OnTarget()) {
		snprintf(message, sizeof(message), "On target. Time: %g", timer.Get() );
		SmartDashboard::PutString(GetName()+"Finish", message);
		return true;
	}
	else if(confirmTime > 0 && timer.Get() > confirmTime) {
		snprintf(message, sizeof(message), "Time's up. Distance: %g", timer.Get() );
		SmartDashboard::PutString(GetName()+"Finish", message);
		return true;
	}
	else {
		return false;
	}
}

double AutonDriveStraight::ReturnPIDInput(){
	return CommandBase::chassis->GetDistance();
}

void AutonDriveStraight::UsePIDOutput(double output){
	if(output > speed) output = speed;
	if(output < -speed) output = -speed;
	CommandBase::chassis->GyroDrive(-output, true);
}

// Called once after isFinished returns true
void AutonDriveStraight::End() {
	GetPIDController()->Disable();
	CommandBase::chassis->m_drive.TankDrive(float(0),float(0));
	timer.Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonDriveStraight::Interrupted() {
	End();
}
