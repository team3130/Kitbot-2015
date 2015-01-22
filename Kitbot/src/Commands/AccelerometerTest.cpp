#include "AccelerometerTest.h"

AccelerometerTest::AccelerometerTest()
{
	Requires(chassis);
}

// Called just before this Command runs the first time
void AccelerometerTest::Initialize()
{


}

// Called repeatedly when this Command is scheduled to run
void AccelerometerTest::Execute()
{
xSpeed = chassis->accelerometer->GetX();
ySpeed = chassis->accelerometer->GetY();
SmartDashboard::PutNumber("X Speed", xSpeed);
SmartDashboard::PutNumber("Y Speed", ySpeed);
}

// Make this return true when this Command no longer needs to run execute()
bool AccelerometerTest::IsFinished()
{
return false;
}

// Called once after isFinished returns true
void AccelerometerTest::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AccelerometerTest::Interrupted()
{
	End();
}
