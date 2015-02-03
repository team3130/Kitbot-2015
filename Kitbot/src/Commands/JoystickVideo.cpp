/*-------------------------------------------------------------------------*/
/* Copyright (c) 2014 FRC-3130 "ERROR 3130". All Rights Reserved.          */
/* Open Source Software - may be modified, shared, used and reused by FRC  */
/* teams under the same license as the WPILib code itself.                 */
/*-------------------------------------------------------------------------*/

#include "JoystickVideo.h"
#include <iostream>

int videoProcess(...)
{
	cv::VideoCapture capture;
	if( capture.open(0, 640,480,7.5) )
	{
		std::cerr<<capture.get(CV_CAP_PROP_FRAME_WIDTH)<<std::endl;
		std::cerr<<capture.get(CV_CAP_PROP_FRAME_HEIGHT)<<std::endl;
		//After Opening Camera we need to configure the returned image setting
		//all opencv v4l2 camera controls scale from 0.0 - 1.0

		capture.set(CV_CAP_PROP_EXPOSURE_AUTO, 1);
		//capture.set(CV_CAP_PROP_EXPOSURE_ABSOLUTE, 0.8);
		capture.set(CV_CAP_PROP_BRIGHTNESS, 0.5);
		capture.set(CV_CAP_PROP_CONTRAST, 0.5);
	}
	else
	{
		std::cerr << "Error: can not connect to the camera\n";
		return 1;
	}

	while( true )
	{
		cv::Mat frame;
		std::vector<unsigned char> outBuffer;
		capture.read(frame);

		if( frame.empty() )
		{
			std::cerr << "Weird.. no frame\n";
			break;
		}
		cv::imencode("jpg",frame,outBuffer);
	}

	return 0;
}



JoystickVideo::JoystickVideo(const char* name) : CommandBase(name)
{
	vthread = new Task("VideoProcess", videoProcess);
	Requires(chassis);
}


// Called just before this Command runs the first time
void JoystickVideo::Initialize() {
	std::cout << "Entering the vision mode...\n";
	if(vthread->IsSuspended()) vthread->Resume();
	else vthread->Start();
}

// Called repeatedly when this Command is scheduled to run
void JoystickVideo::Execute() {
	double powerR = oi->stickR->GetY();
	if(fabs(powerR)<0.1) powerR = 0;
	double powerL = oi->stickL->GetY();
	if(fabs(powerL)<0.1) powerL = 0;
	double power = (powerL + powerR)/2;
	double turn = 0;

	chassis->m_drive.ArcadeDrive(power,turn);
}

// Make this return true when this Command no longer needs to run execute()
bool JoystickVideo::IsFinished() {
	return !oi->rightPrecision->Get();
}

// Called once after isFinished returns true
void JoystickVideo::End() {
	vthread->Suspend();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void JoystickVideo::Interrupted() {
	End();
}


