#ifndef AUTONOMOUS_GROUP_H
#define AUTONOMOUS_GROUP_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "DriveStraightGyro.h"
#include "ControlLifter.h"
#include "ControlRollers.h"

class AutonomousGroup: public CommandGroup
{
private:
	ControlLifter* m_cAutonLifter1;
	ControlLifter* m_cAutonLifter2;
	ControlLifter* m_cAutonLifter3;
	ControlRollers* m_cAutonRollers1;
	ControlRollers* m_cAutonRollers2;
	ControlRollers* m_cAutonRollers3;
	ControlRollers* m_cAutonRollers4;
	DriveStraightGyro* m_cAutonDrive1;
	DriveStraightGyro* m_cAutonDrive2;
	DriveStraightGyro* m_cAutonDrive3;
	DriveStraightGyro* m_cAutonDrive4;
	DriveStraightGyro* m_cAutonDrive5;
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
