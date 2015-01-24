#include "IntakeArms.h"
#include "../RobotMap.h"
#include "../Commands/ControlIntakeArms.h"

IntakeArms::IntakeArms() : Subsystem("IntakeArms")
{
	m_cIntakeControl = new Solenoid(INTAKEARMS);
}

IntakeArms::~IntakeArms(){
	delete m_cIntakeControl;
}

void IntakeArms::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new ControlIntakeArms());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void IntakeArms::ControlArms(bool isExtend)
{
	m_cIntakeControl->Set(isExtend);
}
