#include "IntakeArms.h"
#include "../RobotMap.h"
#include "../Commands/ControlIntakeArms.h"

IntakeArms::IntakeArms() : Subsystem("IntakeArms")
{
	m_cIntakeSolenoidL = new Solenoid(INTAKEARML);
	m_cIntakeSolenoidR = new Solenoid(INTAKEARMR);
}

IntakeArms::~IntakeArms(){
	delete m_cIntakeSolenoidL;
	delete m_cIntakeSolenoidR;
}

void IntakeArms::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new ControlIntakeArms());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void IntakeArms::ControlArms(bool isExtendL, bool isExtendR)
{
	m_cIntakeSolenoidL->Set(isExtendL);
	m_cIntakeSolenoidR->Set(isExtendR);
}
