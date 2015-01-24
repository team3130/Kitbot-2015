#ifndef AUTONOMOUS_GROUP_H
#define AUTONOMOUS_GROUP_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "AutonDriveStraight.h"
#include "ControlLifter.h"
#include "AutonRollers.h"

class AutonomousGroup: public CommandGroup
{
private:
	ControlLifter* m_cAutonLifter1;
	ControlLifter* m_cAutonLifter2;
	ControlLifter* m_cAutonLifter3;
	AutonRollers* m_cAutonRollers1;
	AutonRollers* m_cAutonRollers2;
	AutonRollers* m_cAutonRollers3;
	AutonRollers* m_cAutonRollers4;
	AutonDriveStraight* m_cAutonDrive1;
	AutonDriveStraight* m_cAutonDrive2;
	AutonDriveStraight* m_cAutonDrive3;
	AutonDriveStraight* m_cAutonDrive4;
	AutonDriveStraight* m_cAutonDrive5;
public:
	AutonomousGroup();
	~AutonomousGroup();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
