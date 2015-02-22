#ifndef BINCHER_H
#define BINCHER_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Bincher: public Subsystem
{
private:
	Solenoid* m_cBincher;
	bool m_bIsPinching;
public:
	Bincher();
	~Bincher();
	void InitDefaultCommand();
	void SetPinch(bool isPinch);
	bool IsPinching(){return m_bIsPinching;};
};

#endif
