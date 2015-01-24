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
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void AccelerometerTest::Execute()
{
	dT = timer->Get();
	timer->Reset();
	SmartDashboard::PutNumber("Delta T", dT);
	if(dT <= 0) return;

	//Acceleration returns g-forces, multiplied by g to get SI units
	xAcceleration = accelerometer->GetX() * GRAVITY_ACC;
	yAcceleration = accelerometer->GetY() * GRAVITY_ACC;

	SmartDashboard::PutNumber("X Acceleration", xAcceleration);
	SmartDashboard::PutNumber("Y Acceleration", yAcceleration);

	//"integral" of accleration = speed
	xSpeed += xAcceleration * dT;
	ySpeed += yAcceleration * dT;

	SmartDashboard::PutNumber("X Speed", xSpeed);
	SmartDashboard::PutNumber("Y Speed", ySpeed);

	//"integral" of speed = position
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
