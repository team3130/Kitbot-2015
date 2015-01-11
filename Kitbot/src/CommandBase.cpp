#include "CommandBase.h"
#include "Subsystems/ExampleSubsystem.h"
#include "Subsystems/Intake.h"
#include "Commands/Scheduler.h"
#include "Subsystems/Lifter.h"
#include "Subsystems/BinIntake.h"

// Initialize a single static instance of all of your subsystems to NULL
ExampleSubsystem* CommandBase::chassis = NULL;
Intake* CommandBase::intake = NULL;
OI* CommandBase::oi = NULL;
Lifter* CommandBase::lifter = NULL;
BinIntake* CommandBase::binintake = NULL;

CommandBase::CommandBase(char const *name) :
		Command(name)
{
}

CommandBase::CommandBase() :
		Command()
{

}

void CommandBase::init()
{
	// Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	chassis = new ExampleSubsystem();
	intake = new Intake();
	oi = new OI();
	lifter = new Lifter();
	binintake = new BinIntake();
}
