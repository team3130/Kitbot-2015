#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include <string>
#include "Commands/Command.h"
#include "Subsystems/ExampleSubsystem.h"
#include "Subsystems/Intake.h"
#include "Subsystems/IntakeArms.h"
#include "Subsystems/Lifter.h"
#include "Subsystems/Pusher.h"
#include "Subsystems/Output.h"
#include "Subsystems/MooseLifter.h"
#include "Subsystems/AntlerMoose.h"
#include "OI.h"
#include "WPILib.h"
#include "RobotMap.h"

/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */
class CommandBase: public Command
{
public:
	CommandBase(char const *name);
	CommandBase();
	static void init();
	// Create a single static instance of all of your subsystems
	static Output *output;
	static ExampleSubsystem *chassis;
	static Intake *intake;
	static IntakeArms *intakearms;
	static OI *oi;
	static Lifter *lifter;
	static Pusher *pusher;
	static MooseLifter *mooseLifter;
	static AntlerMoose *antlerMoose;
	static Compressor *compressor;
};

#endif
