#ifndef INTAKE_H
#define INTAKE_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Intake: public Subsystem
{
	enum PresetButton {	kIdle, kIn, kOut, kCCW, kCW };
private:
	Talon* m_cIntake_left;
	Talon* m_cIntake_right;
public:
	//PresetButton preset;
	Intake();
	~Intake();
	void InitDefaultCommand();
	void Speed(float speed);
	void HandleObjects(int leftIntake, int rightIntake);
	double getLeftSpeed();
	double getRightSpeed();
};

#endif
