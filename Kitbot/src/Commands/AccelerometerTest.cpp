#include "AccelerometerTest.h"

AccelerometerTest::AccelerometerTest()
	: dT(0)
	, x(0), y(0), z(0), x0(0), y0(0), z0(0)
	, xSpeed(0), ySpeed(0), zSpeed(0)
	, xAcceleration(0), yAcceleration(0), zAcceleration(0)
{
	accelerometer = new BuiltInAccelerometer();
	timer = new Timer;
}

// Called just before this Command runs the first time
void AccelerometerTest::Initialize()
{
	timer->Reset();
	timer->Start();
	x0 = accelerometer->GetX() * GRAVITY_ACC;
	y0 = accelerometer->GetY() * GRAVITY_ACC;
	z0 = accelerometer->GetZ() * GRAVITY_ACC;
}

// Called repeatedly when this Command is scheduled to run
void AccelerometerTest::Execute()
{
	dT = timer->Get();
	timer->Reset();
	SmartDashboard::PutNumber("Delta T", dT);
	if(dT <= 0) return;

	//Acceleration returns g-forces, multiplied by g to get SI units
	xAcceleration = accelerometer->GetX() * GRAVITY_ACC - x0;
	yAcceleration = accelerometer->GetY() * GRAVITY_ACC - y0;
	zAcceleration = accelerometer->GetZ() * GRAVITY_ACC - z0;

	SmartDashboard::PutNumber("X Acceleration", xAcceleration);
	SmartDashboard::PutNumber("Y Acceleration", yAcceleration);
	SmartDashboard::PutNumber("Z Acceleration", zAcceleration);

	//"integral" of accleration = speed
	xSpeed += xAcceleration * dT;
	ySpeed += yAcceleration * dT;
	zSpeed += zAcceleration * dT;

	SmartDashboard::PutNumber("X Speed", xSpeed);
	SmartDashboard::PutNumber("Y Speed", ySpeed);
	SmartDashboard::PutNumber("Z Speed", zSpeed);

	//"integral" of speed = position
	x += xSpeed * dT;
	y += ySpeed * dT;
	z += zSpeed * dT;

	SmartDashboard::PutNumber("X", x);
	SmartDashboard::PutNumber("Y", y);
	SmartDashboard::PutNumber("Z", z);
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
