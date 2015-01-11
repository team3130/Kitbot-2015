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
void Intake::HandleObjects(int leftIntake, int rightIntake)
{
	float leftSpeed, rightSpeed;
	//determines direction of intake depending on received intake status
	if(leftIntake == 1){
		leftSpeed = 1;
	}else if(leftIntake == -1){
		leftSpeed = -1;
	}else{
		leftSpeed = 0;
	}

	if(rightIntake == 1){
		rightSpeed = 1;
	}else if(rightIntake == -1){
		rightSpeed = -1;
	}else{
		rightSpeed = 0;
	}

	//TODO: Change orientation later depending on actual motor orientation
	intake_left->SetSpeed(leftSpeed);
	intake_right->SetSpeed(rightSpeed);
}
