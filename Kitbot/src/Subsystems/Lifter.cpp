#include "Lifter.h"
#include "../RobotMap.h"
#include "../Commands/ControlLifter.h"

Lifter::Lifter()
	: Subsystem("Lifter")
{
	m_cLiftMotor = new CANTalon(LIFTER);
	m_dLifterPosition = 0;
	m_bIsCalibrated = false;
	m_dEncoderValue=0;
	m_cLiftMotor->SetFeedbackDevice(CANTalon::QuadEncoder);
	m_cLiftMotor->SetSensorDirection(true);
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
		setpoint = Preferences::GetInstance()->GetInt("LifterLevelB", 1000);
		break;
	case 2:
		setpoint = Preferences::GetInstance()->GetInt("LifterLevelX", 320);
		break;
	case 3:
		setpoint = Preferences::GetInstance()->GetInt("LifterLevelY", 550);
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
	m_cLiftMotor->SetControlMode(CANSpeedController::kPercentVbus);
	if(goal>0 and GetLimitSwitchTop()){
		m_cLiftMotor->Set(goal);
	}else if(goal<0 and GetLimitSwitchBot()){
		m_cLiftMotor->Set(goal);
	}else{
			m_cLiftMotor->Set(0);
	}
	if(!GetLimitSwitchBot()){
		m_cLiftMotor->SetPosition(0);
	}
}

bool Lifter::GetLimitSwitchTop()
{
	SmartDashboard::PutBoolean("Lifter-Top Limit Switch", m_cLiftMotor->GetForwardLimitOK());
	return m_cLiftMotor->GetForwardLimitOK();
}

bool Lifter::GetLimitSwitchBot()
{
	SmartDashboard::PutBoolean("Lifter-Bottom Limit Switch", m_cLiftMotor->GetReverseLimitOK());
	return m_cLiftMotor->GetReverseLimitOK();
}
