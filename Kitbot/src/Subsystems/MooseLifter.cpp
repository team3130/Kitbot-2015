#include "MooseLifter.h"
#include "../RobotMap.h"
#include "../Commands/ControlMooseLifter.h"

MooseLifter::MooseLifter()
	: Subsystem("MooseLifter")
{
	m_cMooseSolenoid = new Solenoid(COMPRESSOR, MOOSELIFTER);
	m_cMooseLock = new Solenoid(COMPRESSOR, MOOSELOCK);
	m_cMoosePositionSensor = new DigitalInput(MOOSEPOSITIONSENSOR);
}

MooseLifter::~MooseLifter(){
	delete m_cMooseSolenoid;
	delete m_cMooseLock;
	delete m_cMoosePositionSensor;
}

void MooseLifter::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new ControlMooseLifter());
}

void MooseLifter::MoveMooseLifterSolenoid(bool direction)
{
	m_cMooseSolenoid->Set(direction);
}

void MooseLifter::MoveMooseLock(bool activated)
{
	m_cMooseLock->Set(activated);
}
