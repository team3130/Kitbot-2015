#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <iostream>
#include <stdio.h>
#include <time.h>
#include <list>
#include <math.h>

typedef struct DPstruct {
	clock_t	clk;
	int		x;
	int 	size;
} DataPoint;

const double PERIOD = 1;

int a = clock();
/** Function Headers */
void detectAndDisplay( cv::Mat frame, DataPoint* dp );

/** Global variables */
std::string cascade_name = "cascade.xml";
cv::CascadeClassifier logo_cascade;
std::string window_name = "Capture - Cascade detection";
std::list<DataPoint> tracker;
typedef std::list<DataPoint>::iterator DataPointer;

void trackTarget( cv::Mat frame, DataPoint dp )
{
	const int max_noise = frame.cols / 5;
	tracker.push_back(dp);
	std::cout << "Debug: " << dp.clk << " " << dp.x << " " << dp.size;
	// Drop all expired datapoints
	while( tracker.front().clk + PERIOD*CLOCKS_PER_SEC < dp.clk )
	{
		tracker.pop_front();
	}

	if( tracker.size() > 0 )
	{
		DataPoint avg = {dp.clk,0,0};
		double rough_x = 0;
		int n = 0;
		DataPointer idp;
		for( idp = tracker.begin(); idp != tracker.end(); idp++ )
		{
			rough_x += idp->x;
		}
		rough_x /= tracker.size();
		for( idp = tracker.begin(); idp != tracker.end(); idp++ )
		{
			if( abs(idp->x - rough_x) < max_noise )
			{
				avg.x += idp->x;
				avg.size += idp->size;
				n++;
			}
		}
		if(n > 0)
		{
			avg.x /= n;
			avg.size /= n;
			int target = avg.x + avg.size/2;
			line( frame, cv::Point(target,0), cv::Point(target,frame.rows-1), cv::Scalar(0,240,240) );
		}
		//line( frame, Point(dp.x,0), Point(dp.x,frame.rows-1), Scalar(0,240,0) );
		//line( frame, Point(dp.x+dp.size,0), Point(dp.x+dp.size,frame.rows-1), Scalar(0,240,0) );
		std::cout << "|" << avg.x << " " << avg.size << "|" << tracker.size() << " " << n;
	}
	std::cout << "\n";
}

/** @function detectAndDisplay */
void detectAndDisplay( cv::Mat frame, DataPoint* dp )
{
	std::vector<cv::Rect> found;
	cv::Mat frame_gray;
	static int iframe = 0;

	cvtColor( frame, frame_gray, CV_BGR2GRAY );
	equalizeHist( frame_gray, frame_gray );

	//-- Detect found
	logo_cascade.detectMultiScale(
			frame_gray, found,
			1.1,          // Scale factor
			2,            // Min neighbors
			0|CV_HAAR_SCALE_IMAGE |CV_HAAR_FIND_BIGGEST_OBJECT,
			cv::Size(24, 24)  // Min size
	);

	for( std::size_t i = 0; i < found.size(); i++ )
	{
		if(i==0)
		{
			dp->clk = clock();
			dp->x = found[i].x;
			dp->size = found[i].width;
		}
		cv::Point center( found[i].x + found[i].width*0.5, found[i].y + found[i].height*0.5 );
		cv::Size axes( found[i].width*0.5, found[i].height*0.5);
		cv::ellipse( frame, center, axes, 0, 0, 360, cv::Scalar( 255, 0, 255 ), 4, 8, 0 );
	}
	iframe++;

}

/** @function main */
int main( int argc, const char** argv )
{
	cv::Mat frame;
	cv::VideoCapture capture;
	std::string cameraIP;

	if( !logo_cascade.load( cascade_name ) )
	{
		printf("--(!)Error loading\n"); return -1;
	}

	if(argc>0)
	{
		cameraIP = argv[1];
	}
	else
	{
		std::cerr << "Please specify camera IP";
		return 1;
	}

	//-- 2. Read the video stream
	std::string videoStreamAddress = "http://" + cameraIP +"/mjpg/video.mjpg";
	std::cout << "Opening capture at " << videoStreamAddress << "\n";
	if( capture.open(videoStreamAddress) )
	{
		std::cout << "Stream opened.";
		while( true )
		{
			capture.read(frame);
			DataPoint dp = {0,0,0};

			if( frame.empty() )
			{
				std::cerr << " --(!) No captured frame -- Break!\n";
				break;
			}

			//-- 3. Apply the classifier to the frame
			detectAndDisplay( frame, &dp );
			if( dp.clk != 0 ) trackTarget( frame, dp );
			//-- Show what you got
			cv::imshow( window_name, frame );

			int c = cv::waitKey(10);
			if( (char)c == 'c' ) {
				break;
			}
		}
	}

	return 0;
}
