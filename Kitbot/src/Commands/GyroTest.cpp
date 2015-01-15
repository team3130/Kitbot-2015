#include "GyroTest.h"

GyroTest::GyroTest()
{
	Requires(chassis);
}

// Called just before this Command runs the first time
void GyroTest::Initialize()
{
	goalTime = 1;
	moveSpeed = 0.5;
	chassis->gyro->InitGyro();
	chassis->gyro->Reset();
}

// Called repeatedly when this Command is scheduled to run
void GyroTest::Execute()
{
	angle = chassis->gyro->GetAngle();
	chassis->m_drive.Drive(moveSpeed,-angle * m_dKp);
}

// Make this return true when this Command no longer needs to run execute()
bool GyroTest::IsFinished()
{
	if(timer.Get()>goalTime)return true;
	else return false;
}

// Called once after isFinished returns true
void GyroTest::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GyroTest::Interrupted()
{
	End();
}
