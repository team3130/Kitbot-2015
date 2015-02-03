#include "Lifter.h"
#include "../RobotMap.h"
#include "../Commands/ControlLifter.h"

Lifter::Lifter()
	: Subsystem("Lifter")
{
	m_cLiftMotor = new CANTalon(LIFTER);
	m_cEncoder = new Encoder(ENCODER_A, ENCODER_B, false);
	m_cLiftMotor->SetControlMode(CANSpeedController::kPercentVbus);
	m_dLifterPosition = 0;
	m_dEncoderValue=0;
	m_bManualControl = true;
	m_cEncoder->SetDistancePerPulse(0.01); //purely arbitrary constant just for testing
}

Lifter::~Lifter(){
	delete m_cEncoder;
	delete m_cLiftMotor;
}

void Lifter::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new ControlLifter());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.


//Keeps motors level
/*void Lifter::Balance(float fDirection)
{
	m_dEncoderLeftValue = m_cEncoderL->Get();
	m_dEncoderRightValue = m_cEncoderR->Get();
	//Get fraction from difference in encoder values
	//fDirection ensures that difference will be same proportion for all axis values
	//Code will only do something if fDirection is not 0, aka stick is not neutral
	if(fDirection != 0){
		double dRateDifference;
		//prevents divide-by-zero errors in case of encoders at 0
		if((m_dEncoderLeftValue+m_dEncoderRightValue) != 0){
			dRateDifference = fDirection*(m_dEncoderLeftValue-m_dEncoderRightValue)/(m_dEncoderLeftValue+m_dEncoderRightValue);
		}else{
			dRateDifference = 0;
		}

		//compensates for difference in motors using encoder rate difference
		if(fDirection > 0)
		{
			m_cLiftMotorL->SetSpeed(fDirection-dRateDifference);
			m_cLiftMotorR->SetSpeed(fDirection+dRateDifference);
		}
		else if(!GetLimitSwitchBot())
		{
			m_cLiftMotorL->SetSpeed(fDirection+dRateDifference);
			m_cLiftMotorR->SetSpeed(fDirection-dRateDifference);
		}
		//reset encoders when lifter is at the bottom
		if(GetLimitSwitchBot()){
			m_cEncoderL->Reset();
			m_cEncoderR->Reset();
		}
	}
}
*/

// will change orientation if lift winch runs opposite direction
void Lifter::moveLifter(float goal)
{
	m_cEncoder->GetDistance();
	//when manual control set, gamepad axis controls lifter directly
	//when deactivated, directional buttons control goals and left thumb button activates movement
	//probably change control of this into command
	m_cLiftMotor->Set(goal);
	if(GetLimitSwitchBot()){
		m_cEncoder->Reset();
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

void Lifter::SwitchManualControl()
{
	m_bManualControl = !m_bManualControl;
}

bool Lifter::GetManualControl()
{
	return m_bManualControl;
}
