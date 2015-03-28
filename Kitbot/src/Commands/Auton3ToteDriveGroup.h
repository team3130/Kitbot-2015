#ifndef AUTONOMOUS_3TOTE_DRIVE_GROUP_H
#define AUTONOMOUS_3TOTE_DRIVE_GROUP_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "AutonDriveStraight.h"
#include "AutonLifter.h"
#include "AutonIntakeArms.h"
#include "AutonRollers.h"

class Autonomous3ToteDriveGroup: public CommandGroup
{
private:
	AutonDriveStraight* m_cAutonDriveStraight1;
	AutonDriveStraight* m_cAutonDriveStraight2;
	AutonDriveStraight* m_cAutonDriveStraight3;
	AutonRollers* m_cAutonRollers1;
	AutonRollers* m_cAutonRollers2;
	AutonIntakeArms* m_cAutonArms1;
	AutonIntakeArms* m_cAutonArms2;
	AutonLifter* m_cAutonLifter1;
	AutonLifter* m_cAutonLifter2;
public:
	Autonomous3ToteDriveGroup();
	~Autonomous3ToteDriveGroup();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
