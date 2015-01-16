#include "Output.h"
#include "../RobotMap.h"
#include "../Commands/StepEjection.h"

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
	SetDefaultCommand(new StepEjection);
	//SetDefaultCommand(new GyroTest());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.




