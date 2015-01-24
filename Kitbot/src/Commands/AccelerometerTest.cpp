#include "AccelerometerTest.h"

AccelerometerTest::AccelerometerTest()
	: dT(0)
	, x(0)
	, y(0)
	, xSpeed(0)
	, ySpeed(0)
	, xAcceleration(0)
	, yAcceleration(0)
{
	accelerometer = new BuiltInAccelerometer();
	timer = new Timer;
}

// Called just before this Command runs the first time
void AccelerometerTest::Initialize()
{
	timer->Reset();
}

// Called repeatedly when this Command is scheduled to run
void AccelerometerTest::Execute()
{
	dT = timer->Get();
	timer->Reset();
	if(dT <= 0) return;

	xAcceleration = accelerometer->GetX();
	yAcceleration = accelerometer->GetY();

	SmartDashboard::PutNumber("X Acceleration", xAcceleration);
	SmartDashboard::PutNumber("Y Acceleration", yAcceleration);

	xSpeed += xAcceleration * dT;
	ySpeed += yAcceleration * dT;

	SmartDashboard::PutNumber("X Speed", xSpeed);
	SmartDashboard::PutNumber("Y Speed", ySpeed);

	x += xSpeed * dT;
	y += ySpeed * dT;

	SmartDashboard::PutNumber("X", x);
	SmartDashboard::PutNumber("Y", y);
}

// Make this return true when this Command no longer needs to run execute()
bool AccelerometerTest::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void AccelerometerTest::End()
{
	timer->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AccelerometerTest::Interrupted()
{
	End();
}
