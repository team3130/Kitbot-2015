#include "Lifter.h"
#include "../RobotMap.h"
#include "../Commands/ControlLifter.h"

Lifter::Lifter()
	: Subsystem("Lifter")
{

}

void Lifter::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new ControlLifter());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Lifter::Move(GenericHID *gamepad)
{
	m_cLiftMotorL.SpeedController::Set()
	m_cLiftMotorR.SpeedController::Set()
}
