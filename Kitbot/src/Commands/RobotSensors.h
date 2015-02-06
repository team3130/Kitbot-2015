#ifndef ROBOT_SENSORS_H
#define ROBOT_SENSORS_H

#include "../CommandBase.h"
#include "../Subsystems/AntlerMoose.h"
#include "../Subsystems/Intake.h"
#include "../Subsystems/IntakeArms.h"
#include "../Subsystems/Lifter.h"
#include "../Subsystems/MooseLifter.h"
#include "../Subsystems/Pusher.h"
#include "../Subsystems/ExampleSubsystem.h"
#include "WPILib.h"

class RobotSensors: public CommandBase
{
public:
	RobotSensors();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif

