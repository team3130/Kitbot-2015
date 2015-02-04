#include "MooseLifter.h"
#include "../RobotMap.h"
#include "../Commands/ControlMooseLifter.h"

MooseLifter::MooseLifter()
	: Subsystem("MooseLifter")
{
	m_cMooseSolenoid = new Solenoid(COMPRESSOR, MOOSELIFTER);
	m_cMoosePrevent = new Solenoid(COMPRESSOR, MOOSEPREVENT);
	m_cMoosePositionSensor = new DigitalInput(MOOSEPOSITIONSENSOR);
	m_bActivated = false;
}

MooseLifter::~MooseLifter(){
	delete m_cMooseSolenoid;
	delete m_cMoosePrevent;
	delete m_cMoosePositionSensor;
}

void MooseLifter::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
}

void MooseLifter::MoveMooseLifterSolenoid()
{
	m_bActivated = !m_bActivated;
	m_cMooseSolenoid->Set(m_bActivated);
}
