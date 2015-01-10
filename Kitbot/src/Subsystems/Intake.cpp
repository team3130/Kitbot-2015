#include "Intake.h"
#include "../RobotMap.h"
#include "../Commands/ControlRollers.h"

Intake::Intake() : Subsystem("Intake")
{
	intake_left = new SpeedController(INTAKEL);
	intake_right = new SpeedController(INTAKER);
}

Intake::~Intake(){
	delete intake_left;
	delete intake_right;
}

void Intake::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new ControlRollers());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

//Sets speed of intake mechanism
void Intake::Speed(float speed){
	intake_left->Set(speed, 0);
	intake_right->Set(-speed, 0);
}

//set intake in, out, or neutral depending on current status and buttons pressed
void Intake::HandleObjects(int status)
{
	float speed;
	//determines direction of intake depending on received intake status
	switch(status){
		case 0:
			speed = 0;
			break;
		case 1:
			speed = 1;
			break;
		case -1:
			speed = -1;
			break;
		default:
			speed = 0;
			break;
	}
	intake_left->Set(speed, 0);
	intake_right->Set(-speed, 0);
}
