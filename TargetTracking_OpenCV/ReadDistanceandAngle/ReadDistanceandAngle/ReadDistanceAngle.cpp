#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <iostream>
#include <string>

std::vector<cv::Point2f> Generate2DPoints();
std::vector<cv::Point3f> Generate3DPoints();

int main(int argc, char** argv)
{
	//// Load Image
	std::cout << " Reading " << argv[1] << std::endl;
	cv::Mat Im;
	Im = cv::imread(argv[1], CV_LOAD_IMAGE_COLOR);
	std::cout << Im.rows << " " << Im.cols << " " << Im.channels() <<std::endl;
	cv::namedWindow("Image", CV_WINDOW_AUTOSIZE);
	if (!Im.empty()){
		cv::imshow("window", Im);
	}
	else{
		std::cout << " Error reading image" << std::endl;
	}
	//
	
	cv::waitKey(0);
	std::cout << cv::mean(Im) << std::endl;
	/*cv::cvtColor(Im, Im, CV_BGR2RGB);
	std::cout << "color convert complete" << */
	// Threshold and find yellow image
	cv::Mat YellowIm;
	//YellowIm.create(Im.rows, Im.cols, CV_8U);
	int iLowR = 150;
	int iHighR = 255;

	int iLowG = 150;
	int iHighG = 255;

	int iLowB = 0;
	int iHighB = 100;
	cv::inRange(Im, cv::Scalar(iLowB, iLowG, iLowR), cv::Scalar(iHighB, iHighG, iHighR), YellowIm);
	cv::namedWindow("Yellow", CV_WINDOW_AUTOSIZE);
	cv::imshow("Yellow", YellowIm);
	//Morphology
	
	//morphological opening (remove small objects from the foreground)
	cv::erode(YellowIm, YellowIm, cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(5, 5)));
	cv::dilate(YellowIm, YellowIm, cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(5, 5)));

	//morphological closing (fill small holes in the foreground)
	cv::dilate(YellowIm, YellowIm, cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(5, 5)));
	cv::erode(YellowIm, YellowIm, cv::getStructuringElement(cv::MORPH_ELLIPSE, cv::Size(5, 5)));

	
	cv::waitKey(0);

	//Extract Contours

	// Find Largest Contour

	//Extract Convex Hull of the Largest Contour

	// Read points
	std::vector<cv::Point2f> imagePoints = Generate2DPoints();
	std::vector<cv::Point3f> objectPoints = Generate3DPoints();

	std::cout << "There are " << imagePoints.size() << " imagePoints and " << objectPoints.size() << " objectPoints." << std::endl;
	cv::Mat cameraMatrix(3, 3, cv::DataType<double>::type);
	//cv::setIdentity(cameraMatrix);
	cameraMatrix.at<double>(0, 0) = 1.1535172564418742e+003;
	cameraMatrix.at<double>(0, 1) = 0;
	cameraMatrix.at<double>(0, 2) = 6.3950000000000000e+002;
	cameraMatrix.at<double>(1, 0) = 0;
	cameraMatrix.at<double>(1, 1) = 1.1535172564418742e+003;
	cameraMatrix.at<double>(1, 2) = 3.5950000000000000e+002;
	cameraMatrix.at<double>(2, 0) = 0;
	cameraMatrix.at<double>(2, 1) = 0;
	cameraMatrix.at<double>(2, 2) = 1;

	std::cout << "Initial cameraMatrix: " << cameraMatrix << std::endl;

	cv::Mat distCoeffs(5, 1, cv::DataType<double>::type);
	distCoeffs.at<double>(0) = 9.7778874355990107e-003;
	distCoeffs.at<double>(1) = 1.7729280024159664e+000;
	distCoeffs.at<double>(2) = 0;
	distCoeffs.at<double>(3) = 0;
	distCoeffs.at<double>(4) = -1.8467881770062665e+001;

	std::cout << "Dist Coefficients" << distCoeffs << std::endl;
	
	cv::Mat rvec(3, 1, cv::DataType<double>::type);
	cv::Mat tvec(3, 1, cv::DataType<double>::type);

	cv::solvePnP(cv::Mat(objectPoints), cv::Mat(imagePoints), cameraMatrix, distCoeffs, rvec, tvec, false, CV_EPNP);

	std::cout << "rvec: " << rvec << std::endl;
	std::cout << "tvec: " << tvec << std::endl;

	cv::Mat Rmat(3, 3, cv::DataType<double>::type);
	cv::Rodrigues(rvec, Rmat);
	cv::Mat cameralocation(3, 1, cv::DataType<double>::type);
	cameralocation = -(Rmat.t() * tvec);
	std::cout << "Camera is at:" << cameralocation << " with respect to the middle of the tote" << std::endl;

	/*std::vector<cv::Point2f> projectedPoints;
	cv::projectPoints(objectPoints, rvec, tvec, cameraMatrix, distCoeffs, projectedPoints);

	for (unsigned int i = 0; i < projectedPoints.size(); ++i)
	{
		std::cout << "Image point: " << imagePoints[i] << " Projected to " << projectedPoints[i] << std::endl;
	}
*/
	return 0;
}


std::vector<cv::Point2f> Generate2DPoints()
{
	std::vector<cv::Point2f> points;

	float x, y;


		x = 500; y = 348;
	points.push_back(cv::Point2f(x, y));

	x = 833; y = 348;
	points.push_back(cv::Point2f(x, y));

	x = 833; y = 582; 
	points.push_back(cv::Point2f(x, y));

	x = 500; y = 582; 
	points.push_back(cv::Point2f(x, y));
	/*x = 282; y = 274;
	points.push_back(cv::Point2f(x, y));

	x = 397; y = 227;
	points.push_back(cv::Point2f(x, y));

	x = 577; y = 271;
	points.push_back(cv::Point2f(x, y));

	x = 462; y = 318;
	points.push_back(cv::Point2f(x, y));

	x = 270; y = 479;
	points.push_back(cv::Point2f(x, y));

	x = 450; y = 523;
	points.push_back(cv::Point2f(x, y));

	x = 566; y = 475;
	points.push_back(cv::Point2f(x, y));*/

	for (unsigned int i = 0; i < points.size(); ++i)
	{
		std::cout << points[i] << std::endl;
	}

	return points;
}


std::vector<cv::Point3f> Generate3DPoints()
{
	std::vector<cv::Point3f> points;

	
	float x, y, z;

	x = 0-16.5/2.0; y = 0-6; z = 0.5000;
	points.push_back(cv::Point3f(x, y, z));
	
	x = 16.5000-16.5/2.0; y = 0-6; z = 0.5000;
	points.push_back(cv::Point3f(x, y, z));
	
	x = 16.5000-16.5/2.0; y = 12.0000-6; z = 0.5000;
	points.push_back(cv::Point3f(x, y, z));
	
	x = 0-16.5/2.0; y = 12.0000-6; z = 0.5000;
	points.push_back(cv::Point3f(x, y, z));

	/*x = .5; y = .5; z = -.5;
	points.push_back(cv::Point3f(x, y, z));

	x = .5; y = .5; z = .5;
	points.push_back(cv::Point3f(x, y, z));

	x = -.5; y = .5; z = .5;
	points.push_back(cv::Point3f(x, y, z));

	x = -.5; y = .5; z = -.5;
	points.push_back(cv::Point3f(x, y, z));

	x = .5; y = -.5; z = -.5;
	points.push_back(cv::Point3f(x, y, z));

	x = -.5; y = -.5; z = -.5;
	points.push_back(cv::Point3f(x, y, z));

	x = -.5; y = -.5; z = .5;
	points.push_back(cv::Point3f(x, y, z));*/

	for (unsigned int i = 0; i < points.size(); ++i)
	{
		std::cout << points[i] << std::endl;
	}

	return points;
}