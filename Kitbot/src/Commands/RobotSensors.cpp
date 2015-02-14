#include "RobotSensors.h"

RobotSensors::RobotSensors()
{
	// Use Requires() here to declare subsystem dependencies
	range = new AnalogInput(1);
}

// Called just before this Command runs the first time
void RobotSensors::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void RobotSensors::Execute()
{

	SmartDashboard::PutNumber("Encoder-Value", lifter->GetPosition());
	SmartDashboard::PutBoolean("Pusher-Out Limit Switch", pusher->GetLimitSwitchOut());
	SmartDashboard::PutBoolean("Pusher-In Limit Switch", pusher->GetLimitSwitchIn());
	SmartDashboard::PutBoolean("Lifter-Top Limit Switch", lifter->GetLimitSwitchTop());
	SmartDashboard::PutBoolean("Lifter-Bottom Limit Switch", lifter->GetLimitSwitchBot());
	SmartDashboard::PutBoolean("Magnet Sensor",CommandBase::mooseLifter->isHighEnough());
	SmartDashboard::PutNumber("Gyro Current Angle: ", chassis->gyro->GetAngle());
	SmartDashboard::PutNumber("Gyro Rotation rate: ", chassis->gyro->GetRate());
	SmartDashboard::PutBoolean("Is Using Gyro", chassis->IsUsingGyro());
	SmartDashboard::PutNumber("Analog Input 1", range->GetValue());
	SmartDashboard::PutNumber("Left Encoder", chassis->m_cEncoderL->Get());
	SmartDashboard::PutNumber("Right Encoder", chassis->m_cEncoderR->Get());
	SmartDashboard::PutNumber("Distance", chassis->GetDistance());
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
