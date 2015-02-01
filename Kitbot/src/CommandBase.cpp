#include "CommandBase.h"
#include "Subsystems/ExampleSubsystem.h"
#include "Subsystems/Intake.h"
#include "Subsystems/IntakeArms.h"
#include "Commands/Scheduler.h"
#include "Subsystems/Lifter.h"
#include "Subsystems/Pusher.h"
#include "Commands/AccelerometerTest.h"

// Initialize a single static instance of all of your subsystems to NULL
ExampleSubsystem* CommandBase::chassis = NULL;
Intake* CommandBase::intake = NULL;
IntakeArms* CommandBase::intakearms = NULL;
Output* CommandBase::output = NULL;
OI* CommandBase::oi = NULL;
Lifter* CommandBase::lifter = NULL;
Pusher* CommandBase::pusher = NULL;
MooseLifter* CommandBase::mooseLifter = NULL;
AntlerMoose* CommandBase::antlerMoose = NULL;

Compressor* CommandBase::compressor = NULL;
AccelerometerTest* FPS = NULL;

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
	intakearms = new IntakeArms();
	output = new Output();
	oi = new OI();
	lifter = new Lifter();
	pusher = new Pusher();
	mooseLifter = new MooseLifter();
	antlerMoose = new AntlerMoose();
	FPS = new AccelerometerTest();
	compressor = new Compressor(COMPRESSOR);
	compressor->Start();
	//FPS->Start();
	SmartDashboard::PutData(FPS);
}
