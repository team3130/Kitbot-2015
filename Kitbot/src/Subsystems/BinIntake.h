#ifndef BININTAKE_H
#define BININTAKE_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class BinIntake: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	Talon *m_cBinRotateMotor;

public:
	BinIntake();
	~BinIntake();
	void Spin();
	void InitDefaultCommand();
};

#endif
