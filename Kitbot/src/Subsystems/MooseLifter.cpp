#include "MooseLifter.h"
#include "../RobotMap.h"
#include "../Commands/ControlMooseLifter.h"

MooseLifter::MooseLifter()
	: Subsystem("MooseLifter")
{
	m_cMooseLiftMotor = new Talon(MOOSELIFTER);
	m_cMooseSolonoid = new Solenoid(MOOSELIFTER);
	m_cLimitSwitchTop = new DigitalInput(LIFTERSWITCHTOP);
	m_cLimitSwitchBot = new DigitalInput(LIFTERSWITCHBOT);
	m_dLifterPosition = 0;
	m_dEncoderValue=0;
}

MooseLifter::~MooseLifter(){
	delete m_cLimitSwitchTop;
	delete m_cLimitSwitchBot;
	delete m_cMooseLiftMotor;
}

void MooseLifter::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	SetDefaultCommand(new ControlMooseLifter());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.


//Keeps motors level
/*void MooseLifter::Balance(float fDirection)
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
void MooseLifter::moveMooseLifter(float speed)
{
	if((speed > 0 and !GetLimitSwitchTop()) or (speed < 0 and !GetLimitSwitchBot())){
		m_cMooseLiftMotor->SetSpeed(speed);
	}
}

bool MooseLifter::GetLimitSwitchTop()
{
	return m_cLimitSwitchTop->Get();
}

bool MooseLifter::GetLimitSwitchBot()
{
	return m_cLimitSwitchBot->Get();
}
