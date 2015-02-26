#include "WPILib.h"
#include "Commands/Command.h"
#include "Commands/AutonomousGroup2.h"
#include "Commands/AutonomousGroup.h"
#include "Commands/AutonomousGroup3.h"
#include "Commands/AutonomousGroup4.h"
#include "Commands/AutonomousGroup5.h"
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
		chooser->AddObject("Pick Up Yellow Tote", new AutonomousGroup());
		chooser->AddObject("Drive into Auton Zone", new AutonomousGroup3());
		chooser->AddObject("Pick Up Bin", new AutonomousGroup4());
		chooser->AddObject("No Auton", new AutonomousGroup5());
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

