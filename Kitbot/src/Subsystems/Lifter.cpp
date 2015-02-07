#include "Lifter.h"
#include "../RobotMap.h"
#include "../Commands/ControlLifter.h"

Lifter::Lifter()
	: PIDSubsystem("Lifter",0,0,0)
{
	m_cLiftMotor = new CANTalon(LIFTER);
	m_cLiftMotor->SetControlMode(CANSpeedController::kPercentVbus);
	m_cLiftMotor->SetFeedbackDevice(CANTalon::QuadEncoder);
	m_dLifterPosition = 0;
	m_bIsCalibrated = false;
	m_dEncoderValue=0;
}

Lifter::~Lifter(){
	delete m_cLiftMotor;
}

void Lifter::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new ControlLifter());
}

void Lifter::moveLifter(float goal)
{
	m_cLiftMotor->Set(goal);
	if(GetLimitSwitchBot()){
		m_cLiftMotor->SetPosition(0);
	}
}

double Lifter::ReturnPIDInput(){
	return GetPosition();
}

void Lifter::UsePIDOutput(double output){
	m_cLiftMotor->Set(output);
}

double Lifter::GetPosition()
{
	return m_cLiftMotor->GetPosition();
}

bool Lifter::GetLimitSwitchTop()
{
	return m_cLiftMotor->GetForwardLimitOK();
}

bool Lifter::GetLimitSwitchBot()
{
	return m_cLiftMotor->GetReverseLimitOK();
}
