#include "RobotSensors.h"

bool RobotSensors::lifterZero = false;

RobotSensors::RobotSensors()
{
	arduino = new SerialPort(9600, SerialPort::kMXP);
	timer = new Timer();
	this->SetRunWhenDisabled(true);
}

RobotSensors::~RobotSensors()
{
	delete arduino;
	delete timer;
}

// Called just before this Command runs the first time
void RobotSensors::Initialize()
{
	timer->Reset();
	timer->Start();
	SmartDashboard::PutNumber("SDB Test", 3130);
}

// Called repeatedly when this Command is scheduled to run
void RobotSensors::Execute()
{
	CommandBase::lifter->CheckZero();

	if(false /* DriverStation::GetInstance()->IsDisabled() */) {
		if(timer->Get() > 4) {
			timer->Reset();
			timer->Start();
			if(!lifterZero) {
				arduino->Write("Z", 1);
			}
/*			else if(DriverStation::GetInstance()->IsDSAttached()) {
				if(DriverStation::GetInstance()->GetAlliance() == DriverStation::kBlue)	arduino->Write("B", 1);
				else if(DriverStation::GetInstance()->GetAlliance() == DriverStation::kRed)	arduino->Write("R", 1);
				else arduino->Write("U", 1);
			} */
			else {
				arduino->Write("E", 1);
			}
		}
	}
	else {
		if(timer->Get() > 1.0) {
			timer->Reset();
			timer->Start();

			if( chassis->m_cEncoderL->GetRate() > 6 ) arduino->Write("3", 1);
			else if( chassis->m_cEncoderL->GetRate() < -6 ) arduino->Write("4", 1);
			else arduino->Write("5", 1);

			if( lifter->GetSpeed() > 0.5 ) arduino->Write("6", 1);
			else if(lifter->GetSpeed() < -0.5) arduino->Write("7", 1);
			else arduino->Write("8", 1);

			if( CommandBase::pusher->GetDir() > 0) arduino->Write("9", 1);
			else if( CommandBase::pusher->GetDir() < 0) arduino->Write("10", 1);
			else arduino->Write("11", 1);

			if(!lifterZero) {
				arduino->Write("Z", 1);
			}
		}
	}

	SmartDashboard::PutNumber("Encoder-Value", lifter->GetPosition());
	SmartDashboard::PutBoolean("Pusher-Out Limit Switch", pusher->GetLimitSwitchOut());
	SmartDashboard::PutBoolean("Pusher-In Limit Switch", pusher->GetLimitSwitchIn());
	SmartDashboard::PutBoolean("Lifter-Top Limit Switch", lifter->GetLimitSwitchTop());
	SmartDashboard::PutBoolean("Lifter-Bottom Limit Switch", lifter->GetLimitSwitchBot());
	SmartDashboard::PutBoolean("Magnet Sensor",CommandBase::mooseLifter->isHighEnough());
//	SmartDashboard::PutNumber("Gyro Current Angle: ", chassis->gyro->GetAngle());
//	SmartDashboard::PutNumber("Gyro Rotation rate: ", chassis->gyro->GetRate());
	SmartDashboard::PutNumber("Encoder Angle: ", chassis->GetAngle());
	SmartDashboard::PutBoolean("Is Using Gyro", chassis->IsUsingGyro());
	SmartDashboard::PutBoolean("Is Left Antler Down", antlerMoose->IsLeftAntlerDown());
	SmartDashboard::PutBoolean("Is Right Antler Down", antlerMoose->IsRightAntlerDown());
	SmartDashboard::PutNumber("Left Encoder", chassis->m_cEncoderL->GetDistance());
	SmartDashboard::PutNumber("Right Encoder", chassis->m_cEncoderR->GetDistance());
	SmartDashboard::PutNumber("Distance", chassis->GetDistance());
	SmartDashboard::PutNumber("Angle Setpoint", chassis->GetPIDController()->GetSetpoint());
//	SmartDashboard::PutNumber("SDB Test", SmartDashboard::GetNumber("SDB Test"));
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
