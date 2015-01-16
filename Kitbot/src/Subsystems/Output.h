#ifndef OUTPUT_H
#define OUTPUT_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Output: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:

	Output();
	~Output();
	void InitDefaultCommand();
};

#endif
