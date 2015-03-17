#include "RobotSensors.h"

RobotSensors::RobotSensors()
{
	// Use Requires() here to declare subsystem dependencies
	range = new AnalogInput(1);
	arduino = new SerialPort(9600, SerialPort::kMXP);
	timer = new Timer();
	this->SetRunWhenDisabled(true);
	light = '1';
}

RobotSensors::~RobotSensors()
{
	delete range;
	delete arduino;
	delete timer;
}

// Called just before this Command runs the first time
void RobotSensors::Initialize()
{
	timer->Reset();
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void RobotSensors::Execute()
{
	if(DriverStation::GetInstance()->IsDisabled()) {
		if(timer->Get() > 4) {
			timer->Reset();
			timer->Start();
			if(DriverStation::GetInstance()->IsDSAttached()) {
				if(DriverStation::GetInstance()->GetAlliance() == DriverStation::kBlue)	arduino->Write("B", 1);
				else if(DriverStation::GetInstance()->GetAlliance() == DriverStation::kRed)	arduino->Write("R", 1);
				else arduino->Write("U", 1);
			}
			else {
				arduino->Write("E", 1);
			}
		}
	}
	else {
		if( chassis->m_cEncoderL->GetRate() > 6 ) arduino->Write("3", 1);
		else if( chassis->m_cEncoderL->GetRate() < -6 ) arduino->Write("4", 1);
		else arduino->Write("5", 1);

		if( lifter->GetSpeed() > 0.5 ) arduino->Write("6", 1);
		else if(lifter->GetSpeed() < -0.5) arduino->Write("7", 1);
		else arduino->Write("8", 1);

		if( CommandBase::pusher->GetDir() > 0) arduino->Write("9", 1);
		else if( CommandBase::pusher->GetDir() < 0) arduino->Write("10", 1);
		else arduino->Write("11", 1);
	}

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
	SmartDashboard::PutBoolean("Is Left Antler Down", antlerMoose->IsLeftAntlerDown());
	SmartDashboard::PutBoolean("Is Right Antler Down", antlerMoose->IsRightAntlerDown());
	SmartDashboard::PutNumber("Left Encoder", chassis->m_cEncoderL->GetDistance());
	SmartDashboard::PutNumber("Right Encoder", chassis->m_cEncoderR->GetDistance());
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
