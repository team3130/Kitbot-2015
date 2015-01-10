#ifndef INTAKE_H
#define INTAKE_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Intake: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Talon* intake_left;
	Talon* intake_right;
public:
	Intake();
	~Intake();
	void InitDefaultCommand();
	void Speed(float speed);
	void HandleObjects(int status);
};

#endif
