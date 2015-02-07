#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/AutonomousGroup.h"
#include "Commands/RobotSensors.h"
#include "CommandBase.h"

class Robot: public IterativeRobot
{
private:
	Command *autonomousCommand;
	Command *robotSensors;
	LiveWindow *lw;

	void RobotInit()
	{
		CommandBase::init();
		autonomousCommand = new AutonomousGroup();
		robotSensors = new RobotSensors();
		lw = LiveWindow::GetInstance();
	}
	
	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{
		if (autonomousCommand != NULL)
			autonomousCommand->Start();
	}

	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TeleopInit()
	{
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (autonomousCommand != NULL)
			autonomousCommand->Cancel();
		robotSensors->Start();
	}

	void TeleopPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void TestPeriodic()
	{
		lw->Run();
	}
};

START_ROBOT_CLASS(Robot);

