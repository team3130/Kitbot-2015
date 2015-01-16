#include "Output.h"
#include "../RobotMap.h"
#include "../Commands/DriveStraightGyro.h"
#include "../Commands/GyroTest.h"

Output::Output()
	: Subsystem("Output")
{

}

Output::~Output()
{
}

void Output::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new DriveStraightGyro("Default drive"));
	//SetDefaultCommand(new GyroTest());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.




