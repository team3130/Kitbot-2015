/*-------------------------------------------------------------------------*/
/* Copyright (c) 2014 FRC-3130 "ERROR 3130". All Rights Reserved.          */
/* Open Source Software - may be modified, shared, used and reused by FRC  */
/* teams under the same license as the WPILib code itself.                 */
/*-------------------------------------------------------------------------*/

#include "JoystickVideo.h"
#include <iostream>
#include <pthread.h>

struct ProgParams
{
	bool USB_Cam;
	int detected_x;
};

/*
// Grey tote
const int H_MIN = 8;
const int H_MAX = 48;
const int S_MIN = 18;
const int S_MAX = 81;
const int V_MIN = 37;
const int V_MAX = 156;
*/
// Yellow tote
const int H_MIN = 8;
const int H_MAX = 48;
const int S_MIN = 160;
const int S_MAX = 255;
const int V_MIN = 128;
const int V_MAX = 255;

//default capture width and height
const int FRAME_WIDTH = 640;
const int FRAME_HEIGHT = 360;
//max number of objects to be detected in frame
const int MAX_NUM_OBJECTS=50;
//minimum and maximum object area
const int MIN_OBJECT_AREA = FRAME_HEIGHT*FRAME_WIDTH/10.0;
const int MAX_OBJECT_AREA = FRAME_HEIGHT*FRAME_WIDTH/1.5;

pthread_t MJPEG;
pthread_mutex_t xMutex = PTHREAD_MUTEX_INITIALIZER;
ProgParams params;

int trackFilteredObject(cv::Mat img)
{
	cv::Mat temp;
	img.copyTo(temp);

	//these two vectors needed for output of findContours
	std::vector<std::vector<cv::Point>> contours;
	std::vector<cv::Vec4i> hierarchy;

	//find contours of filtered image using openCV findContours function
	cv::findContours(temp, contours, hierarchy, cv::RETR_CCOMP, cv::CHAIN_APPROX_SIMPLE );
	//use moments method to find our filtered object
	double refArea = 0;
	bool objectFound = false;
	int x;
	if (hierarchy.size() > 0 and hierarchy.size() < MAX_NUM_OBJECTS )
	{
		for (int index = 0; index >= 0; index = hierarchy[index][0])
		{
			cv::Moments moment = cv::moments((cv::Mat)contours[index]);
			double area = moment.m00;

			//we only want the object with the largest area so we save a reference area each
			//iteration and compare it to the area in the next iteration.
			if(area>MIN_OBJECT_AREA && area<MAX_OBJECT_AREA && area>refArea)
			{
				x = moment.m10/area;
				//y = moment.m01/area;
				objectFound = true;
				refArea = area;
			}
		}
	}
	//let user know you found an object
	if(objectFound)
	{
		// putText(cameraFeed,"Tracking Object",Point(0,50),2,1,Scalar(0,255,0),2);
		// drawObject(x,y,cameraFeed);
		return x - FRAME_WIDTH/2;
	}
	else
	{
		// putText(cameraFeed,"TOO MUCH NOISE! ADJUST FILTER",Point(0,50),1,2,Scalar(0,0,255),2);
		return 0;
	}
}

void *videoProcess(void *args)
{
	ProgParams *param_ptr = (ProgParams *) args;

	cv::VideoCapture capture;
	if( capture.open(0, FRAME_WIDTH, FRAME_HEIGHT, 7.5) )
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
		return NULL;
	}

	cv::Mat erodeElement = cv::getStructuringElement( cv::MORPH_RECT,cv::Size(3,3));
	cv::Mat dilateElement = cv::getStructuringElement( cv::MORPH_RECT,cv::Size(8,8));


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

		cv::Mat hsv, bitmap;
		cvtColor(frame, hsv, cv::COLOR_BGR2HSV);
		cv::inRange(hsv, cv::Scalar(H_MIN,S_MIN,V_MIN), cv::Scalar(H_MAX,S_MAX,V_MAX), bitmap);
		cv::erode(bitmap,bitmap,erodeElement);
		cv::erode(bitmap,bitmap,erodeElement);
		cv::dilate(bitmap,bitmap,dilateElement);
		cv::dilate(bitmap,bitmap,dilateElement);
		int x = trackFilteredObject(bitmap);
		//cv::imencode(".jpg",frame,outBuffer);

		pthread_mutex_lock(&xMutex);
		param_ptr->detected_x = x;
		pthread_mutex_unlock(&xMutex);
	}
	return NULL;
}



JoystickVideo::JoystickVideo(const char* name)
	: CommandBase(name)
	, timer()
{
	Requires(chassis);
	pthread_create(&MJPEG, NULL, videoProcess, &params);
}


// Called just before this Command runs the first time
void JoystickVideo::Initialize() {
	std::cout << "Entering the vision mode...\n";
	chassis->HoldAngle(chassis->GetAngle());
	timer.Reset();
	timer.Start();
}

// Called repeatedly when this Command is scheduled to run
void JoystickVideo::Execute() {
	double power = oi->stickL->GetY();
	double speedMultiplier = (-0.5 * oi->stickL->GetZ()) + 0.5;

	if(timer.Get() > 1.5) {
		pthread_mutex_lock(&xMutex);
		int target = params.detected_x;
		pthread_mutex_unlock(&xMutex);

		double angle = 69.0 * target / FRAME_WIDTH;

		SmartDashboard::PutNumber("Vision returns", target);
		chassis->HoldAngle(chassis->GetAngle() + angle);
		timer.Reset();
		timer.Start();
	}
	chassis->GyroDrive(power*speedMultiplier);
}

// Make this return true when this Command no longer needs to run execute()
bool JoystickVideo::IsFinished() {
	return !oi->VideoTest->Get();
}

// Called once after isFinished returns true
void JoystickVideo::End() {
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void JoystickVideo::Interrupted() {
	End();
}


