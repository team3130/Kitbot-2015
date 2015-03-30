#include "AutonWaitForFinished.h"

AutonWaitForFinished::AutonWaitForFinished()
	: m_Slacker(NULL)
{
}

AutonWaitForFinished::AutonWaitForFinished(double timeout)
	: Command(((std::stringstream&)(std::stringstream("WaitForFinished(") << timeout << ")")).str().c_str(), timeout)
	, m_Slacker(NULL)
{
}

void AutonWaitForFinished::Initialize()
{
}

void AutonWaitForFinished::Execute()
{
}

bool AutonWaitForFinished::IsFinished()
{
	return m_Slacker && !m_Slacker->IsRunning();
}

void AutonWaitForFinished::End()
{
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutonWaitForFinished::Interrupted()
{
	End();
}
