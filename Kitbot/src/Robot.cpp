#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/AutonomousGroup2.h"
#include "Commands/AutonomousGroup.h"
#include "Commands/RobotSensors.h"
#include "CommandBase.h"

class Robot: public IterativeRobot
{
private:
	Command *autonomousCommand;
	Command *robotSensors;
	SendableChooser *chooser;
	LiveWindow *lw;

	void RobotInit()
	{
		CommandBase::init();
		chooser = new SendableChooser();
		chooser->AddDefault("Moose Bin Grabber", new AutonomousGroup2());
		chooser->AddObject("Bin Onto Yellow Tote", new AutonomousGroup());
		SmartDashboard::PutData("Autonomous Modes", chooser);
		robotSensors = new RobotSensors();
		lw = LiveWindow::GetInstance();
		robotSensors->Start();	}
	
	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
	}

	void AutonomousInit()
	{
		autonomousCommand = (Command *)chooser->GetSelected();
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

