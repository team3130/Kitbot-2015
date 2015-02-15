#include "CommandBase.h"
#include "Subsystems/ExampleSubsystem.h"
#include "Subsystems/Intake.h"
#include "Subsystems/IntakeArms.h"
#include "Subsystems/Lifter.h"
#include "Subsystems/Pusher.h"
#include "Subsystems/MooseLifter.h"
#include "Subsystems/AntlerMoose.h"
#include "Commands/Scheduler.h"
#include "Commands/AccelerometerTest.h"
#include "Commands/SavePreferences.h"
#include "Commands/PusherLED.h"

// Initialize a single static instance of all of your subsystems to NULL
ExampleSubsystem* CommandBase::chassis = NULL;
Intake* CommandBase::intake = NULL;
IntakeArms* CommandBase::intakearms = NULL;
OI* CommandBase::oi = NULL;
Lifter* CommandBase::lifter = NULL;
Pusher* CommandBase::pusher = NULL;
MooseLifter* CommandBase::mooseLifter = NULL;
AntlerMoose* CommandBase::antlerMoose = NULL;

Compressor* CommandBase::compressor = NULL;
//AccelerometerTest* FPS = NULL;
SavePreferences* save = NULL;
PusherLED* led = NULL;

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
	save = new SavePreferences();
	SmartDashboard::PutData(save);
	led = new PusherLED();
	SmartDashboard::PutData(led);
	chassis = new ExampleSubsystem();
	intake = new Intake();
	intakearms = new IntakeArms();
	oi = new OI();
	lifter = new Lifter();
	pusher = new Pusher();
	mooseLifter = new MooseLifter();
	antlerMoose = new AntlerMoose();
	compressor = new Compressor(COMPRESSOR);
	compressor->Start();
	//FPS = new AccelerometerTest();
	//FPS->Start();
	//SmartDashboard::PutData(FPS);
}
