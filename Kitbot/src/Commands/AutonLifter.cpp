#include "AutonLifter.h"

AutonLifter::AutonLifter()
	: PIDCommand(0.06, 0, 0.1)
	, m_waitTime(0)
	, m_dThreshold(0)
	, m_dEncoderGoal(0)
{
	Requires(CommandBase::lifter);
	timer = new Timer();
}

void AutonLifter::SetGoal(double timeout, double thresh, double goal){
	m_waitTime = timeout;
	m_dThreshold = thresh;
	m_dEncoderGoal = goal;
	GetPIDController()->SetSetpoint(m_dEncoderGoal);
	GetPIDController()->SetAbsoluteTolerance(m_dThreshold);
}

// Called just before this Command runs the first time
void AutonLifter::Initialize()
{
	GetPIDController()->Disable();
	GetPIDController()->SetSetpoint(m_dEncoderGoal);
	GetPIDController()->SetAbsoluteTolerance(m_dThreshold);
	GetPIDController()->Reset();
	GetPIDController()->Enable();
	timer->Reset();
	timer->Start();
}

// Called repeatedly when this Command is scheduled to run
void AutonLifter::Execute()
{
}

// Make this return true when this Command no longer needs to run execute()
bool AutonLifter::IsFinished()
{
	return (GetPIDController()->OnTarget() ||
			(m_waitTime > 0 && timer->Get() > m_waitTime) ||
			!CommandBase::lifter->GetLimitSwitchTop() ||
			!CommandBase::lifter->GetLimitSwitchBot());
}

double AutonLifter::ReturnPIDInput(){
	return CommandBase::lifter->GetPosition();
}

void AutonLifter::UsePIDOutput(double output){
	CommandBase::lifter->toSetpoint(output);
}

// Called once after isFinished returns true
void AutonLifter::End()
{
	GetPIDController()->Disable();
	CommandBase::lifter->toSetpoint(CommandBase::lifter->GetPosition());
	timer->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonLifter::Interrupted()
{
	End();
}
