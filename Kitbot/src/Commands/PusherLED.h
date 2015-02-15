#ifndef PUSHER_LED_H
#define PUSHER_LED_H

#include "../CommandBase.h"
#include "WPILib.h"

class PusherLED: public CommandBase
{
public:
	PusherLED();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
