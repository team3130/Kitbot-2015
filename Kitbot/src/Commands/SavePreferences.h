#ifndef SAVE_PREFERENCES_H
#define SAVE_PREFERENCES_H

#include "../CommandBase.h"
#include "WPILib.h"

class SavePreferences: public CommandBase
{
public:
	SavePreferences();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
