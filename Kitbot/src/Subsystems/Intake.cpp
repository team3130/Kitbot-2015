#include "Intake.h"
#include "../RobotMap.h"
#include "../Commands/ControlRollers.h"

Intake::Intake() : Subsystem("Intake")
{
	intake_left = new Talon(INTAKEL);
	intake_right = new Talon(INTAKER);
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
	//TODO: Change orientation later depending on actual motor orientation
	intake_left->SetSpeed(speed);
	intake_right->SetSpeed(-speed);
}

//set intake in, out, or neutral depending on current status and buttons pressed
void Intake::HandleObjects(int status)
{
	float speed;
	//determines direction of intake depending on received intake status
	if(status == 1){
		speed = 1;
	}else if(status == -1){
		speed = -1;
	}else{
		speed = 0;
	}

	//TODO: Change orientation later depending on actual motor orientation
	intake_left->SetSpeed(speed);
	intake_right->SetSpeed(-speed);
}
