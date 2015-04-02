#include "Lifter.h"
#include "../RobotMap.h"
#include "../Commands/ControlLifter.h"
#include "../Commands/RobotSensors.h"

Lifter::Lifter()
	: Subsystem("Lifter")
	, m_bOnPID(false)
{
	m_cLiftMotor = new CANTalon(LIFTER);
	m_cLiftMotor->ConfigLimitMode(CANTalon::kLimitMode_SwitchInputsOnly);
	m_cLiftMotor->ConfigNeutralMode(CANTalon::kNeutralMode_Brake);
	m_cLiftMotor->SetFeedbackDevice(CANTalon::QuadEncoder);
	m_cLiftMotor->SetControlMode(CANSpeedController::kPercentVbus);
	m_cLiftMotor->SetSensorDirection(false);
	m_cLiftMotor->SetPID(0.05,0,0);
	m_cLiftMotor->SetVoltageRampRate(125.0);
}

Lifter::~Lifter(){
	delete m_cLiftMotor;
}

void Lifter::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new ControlLifter());
}

void Lifter::toSetpoint(int goal)
{
	if(!m_bOnPID) {
		m_bOnPID = true;
		double termP = Preferences::GetInstance()->GetInt("LifterPIDtermP", 5);
		double termI = Preferences::GetInstance()->GetInt("LifterPIDtermI", 0);
		double termD = Preferences::GetInstance()->GetInt("LifterPIDtermD", 0);
		m_cLiftMotor->SetVoltageRampRate(125.0);
		m_cLiftMotor->SetControlMode(CANSpeedController::kPosition);
		m_cLiftMotor->SetPID(termP,termI,termD);
		m_cLiftMotor->EnableControl();
	}
	m_cLiftMotor->Set(goal);
}

void Lifter::moveLifter(float goal)
{
	m_bOnPID = false;
	m_cLiftMotor->SetVoltageRampRate(125.0);
	if(goal > 0 and GetLimitSwitchTop()){
		m_cLiftMotor->SetControlMode(CANSpeedController::kPercentVbus);
		if(GetPosition() > Preferences::GetInstance()->GetInt("LifterSlowZoneTop", 4700)){	//Default number is 5450
			m_cLiftMotor->Set(0.5*goal);
		}else{
			m_cLiftMotor->Set(goal);
		}
	}else if(goal < 0 and GetLimitSwitchBot()){
		m_cLiftMotor->SetControlMode(CANSpeedController::kPercentVbus);
		if(GetPosition() < Preferences::GetInstance()->GetInt("LifterSlowZoneBot", 600)){	//Default number is 400
			m_cLiftMotor->Set(0.5*goal);
		}else{
			m_cLiftMotor->Set(goal);
		}
	}else if(m_cLiftMotor->GetControlMode() == CANSpeedController::kPercentVbus){
		toSetpoint(GetPosition());
	}
	CheckZero();
}

bool Lifter::CheckZero() {
	if(GetLimitSwitchBot()){
		m_cLiftMotor->SetPosition(0);
		RobotSensors::LifterReset();
		return true;
	}
	else return false;
}

