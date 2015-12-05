#include "AccelerometerTest.h"

AccelerometerTest::AccelerometerTest()
	: dT(0), a(3), g(3)
{
	accelerometer = new BuiltInAccelerometer();
	timer = new Timer;
}

// Called just before this Command runs the first time
void AccelerometerTest::Initialize()
{
	timer->Reset();
	timer->Start();

	// Vector g points to the center of the Earth when robot is level and stationary
	g[0] = accelerometer->GetX();
	g[1] = accelerometer->GetY();
	g[2] = accelerometer->GetZ();

	// Actually, since we know the geometry of the robot:
	// axis X points to the left,
	// axis Y points down,
	// axis Z points back
	// we could initialize it statically as {0, 1, 0}
}

// In mathematics and vector calculus, the cross product is a binary operation on two vectors in three-dimensional space (R3)
// Search Wikipedia: "Cross product" for details
//
std::valarray<double> CrossProduct(std::valarray<double> const &a, std::valarray<double> const &b)
{
  std::valarray<double> r(3);
  r[0] = a[1]*b[2]-a[2]*b[1];
  r[1] = a[2]*b[0]-a[0]*b[2];
  r[2] = a[0]*b[1]-a[1]*b[0];
  return r;
}

double magn(std::valarray<double> const x)
{
	return sqrt(x[0]*x[0] + x[1]*x[1] + x[2]*x[2]);
}

// Called repeatedly when this Command is scheduled to run
void AccelerometerTest::Execute()
{
	dT = timer->Get();
	timer->Reset();
	SmartDashboard::PutNumber("Delta T", dT);
	if(dT <= 0) return;

	//Acceleration returns g-forces
	a[0] = accelerometer->GetX();
	a[1] = accelerometer->GetY();
	a[2] = accelerometer->GetZ();

	SmartDashboard::PutNumber("X Acceleration", a[0]);
	SmartDashboard::PutNumber("Y Acceleration", a[1]);
	SmartDashboard::PutNumber("Z Acceleration", a[2]);

	std::valarray<double> c(3);
	c = CrossProduct(g, a);
	double sine = c[0] / sqrt(magn(g) * magn(a));
	SmartDashboard::PutNumber("Tilt (sine)", sine);
	SmartDashboard::PutNumber("Tilt (danger)", sine > 0.5);

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
