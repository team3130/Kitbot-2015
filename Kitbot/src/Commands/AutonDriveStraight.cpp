#include "AutonDriveStraight.h"
#include <math.h>

// Used be constructed with (300,0.05,1,0,0,0)
AutonDriveStraight::AutonDriveStraight()
	: PIDCommand(0.06, 0, 0.1)
	, speed(0)
	, goal(0)
	, threshold(0)
	, confirmTime(0)
{
	Requires(CommandBase::chassis);
}

void AutonDriveStraight::SetGoal(double dist, double thresh, double ispeed) {
	goal=dist;
	threshold=thresh;
	speed = ispeed;
	GetPIDController()->SetSetpoint(goal);
	GetPIDController()->SetAbsoluteTolerance(threshold);
}

// Called just before this Command runs the first time
void AutonDriveStraight::Initialize() {
	GetPIDController()->Disable();
	GetPIDController()->SetSetpoint(goal);
	GetPIDController()->SetAbsoluteTolerance(threshold);
	CommandBase::chassis->ResetEncoders();
	CommandBase::chassis->HoldAngle(0.0);
	GetPIDController()->Reset();
	GetPIDController()->Enable();
}

// Called repeatedly when this Command is scheduled to run
void AutonDriveStraight::Execute() {
}

// Make this return true when this Command no longer needs to run execute()
bool AutonDriveStraight::IsFinished(){
	return GetPIDController()->OnTarget();
}

double AutonDriveStraight::ReturnPIDInput(){
	return CommandBase::chassis->GetDistance();
}

void AutonDriveStraight::UsePIDOutput(double output){
	if(output > speed) output = speed;
	if(output < -speed) output = -speed;
	CommandBase::chassis->GyroDrive(-output);
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
