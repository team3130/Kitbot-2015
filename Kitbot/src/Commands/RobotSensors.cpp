#include "RobotSensors.h"

RobotSensors::RobotSensors()
{
	// Use Requires() here to declare subsystem dependencies
}

// Called just before this Command runs the first time
void RobotSensors::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void RobotSensors::Execute()
{
	SmartDashboard::PutNumber("Intake-Left Speed",CommandBase::intake->m_cIntake_left->Get());
	SmartDashboard::PutNumber("Intake-Right Speed",CommandBase::intake->m_cIntake_right->Get());
	SmartDashboard::PutNumber("Encoder-Value", CommandBase::lifter->m_cLiftMotor->GetPosition());
	//SmartDashboard::PutBoolean("Pusher-Out Limit Switch",CommandBase::pusher-> m_cPushMotor->GetForwardLimitOK());
	//SmartDashboard::PutBoolean("Pusher-In Limit Switch",CommandBase::pusher-> m_cPushMotor->GetReverseLimitOK());
	SmartDashboard::PutBoolean("Lifter-Top Limit Switch",CommandBase::lifter-> m_cLiftMotor->GetForwardLimitOK());
	SmartDashboard::PutBoolean("Lifter-Bottom Limit Switch",CommandBase::lifter-> m_cLiftMotor->GetReverseLimitOK());


}

// Make this return true when this Command no longer needs to run execute()
bool RobotSensors::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void RobotSensors::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void RobotSensors::Interrupted()
{

}
