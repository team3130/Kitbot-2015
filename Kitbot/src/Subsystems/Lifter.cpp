#include "Lifter.h"
#include "../RobotMap.h"
#include "../Commands/ControlLifter.h"

Lifter::Lifter()
	: Subsystem("Lifter")
{
	m_cLiftMotor = new CANTalon(LIFTER);
	m_cLiftMotor->ConfigLimitMode(CANTalon::kLimitMode_SwitchInputsOnly);
	m_cLiftMotor->ConfigNeutralMode(CANTalon::kNeutralMode_Brake);
	m_cLiftMotor->SetFeedbackDevice(CANTalon::QuadEncoder);
	m_cLiftMotor->SetSensorDirection(false);
	m_cLiftMotor->SetPID(0.05,0,0);
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
	double setpoint;
	double termP = Preferences::GetInstance()->GetInt("LifterPIDtermP", 20);
	switch(goal) {
	case 0:
		setpoint = 0;
		break;
	case 1:
		setpoint = Preferences::GetInstance()->GetInt("LifterLevelB", 1682);
		break;
	case 2:
		setpoint = Preferences::GetInstance()->GetInt("LifterLevelX", 983);
		break;
	case 3:
		setpoint = Preferences::GetInstance()->GetInt("LifterLevelY", 523);
		break;
	default:
		std::cerr << "ERRORL wrong lifter goal index" << std::endl;
		return;
	}
	m_cLiftMotor->SetControlMode(CANSpeedController::kPosition);
	m_cLiftMotor->SetPID(termP,0,0);
	m_cLiftMotor->Set(setpoint);
	m_cLiftMotor->EnableControl();
}

void Lifter::moveLifter(float goal)
{
	if(goal>0.1 and GetLimitSwitchTop()){
		m_cLiftMotor->SetControlMode(CANSpeedController::kPercentVbus);
		m_cLiftMotor->Set(goal);
	}else if(goal<-0.1 and GetLimitSwitchBot()){
		m_cLiftMotor->SetControlMode(CANSpeedController::kPercentVbus);
		m_cLiftMotor->Set(goal);
	}else if(m_cLiftMotor->GetControlMode() == CANSpeedController::kPercentVbus){
		m_cLiftMotor->SetControlMode(CANSpeedController::kPosition);
		m_cLiftMotor->Set(GetPosition());
		m_cLiftMotor->EnableControl();
	}
	if(!GetLimitSwitchBot()){
		m_cLiftMotor->SetPosition(0);
	}
}

