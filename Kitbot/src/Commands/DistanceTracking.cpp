#include "DistanceTracking.h"

// constants
const double kCalibratedHeight_px			= 100.0;
const double kCalibratedDistance_ft			= 10.0;
const double kdDistanceBetweenReference_ft	= 1.2;
const double k90DegreesInRadians			= 1.57079633;

const int MARKER_ONE = 0;

// constructor
DistanceTracking::DistanceTracking() {
}

// get the distance to the wall on the line being aimed at
double DistanceTracking::GetDistanceToTarget() {
	try
	{
		NetworkTable * pNetworkTable = NetworkTable::GetTable("RoboRealm");
		
		double dDistance_ft = 0.0;
	
		if ( pNetworkTable && pNetworkTable->IsConnected()) {
	
			if ( !pNetworkTable->ContainsKey("COG_X") ||
				 !pNetworkTable->ContainsKey("COG_Y") ||
				 !pNetworkTable->ContainsKey("COG_BOX_SIZE") ||
				 !pNetworkTable->ContainsKey("COG_DENSITY") ||
				 !pNetworkTable->ContainsKey("IMAGE_WIDTH") ||
				 !pNetworkTable->ContainsKey("IMAGE_HEIGHT")) {
				return 0.0;
			}

			double dDistanceBase_ft = 0.0;
			SDoublePoint cog;
			SDoublePoint center;

			cog.x = pNetworkTable->GetNumber("COG_X");
			cog.y = pNetworkTable->GetNumber("COG_Y");
			double dCogWidth = pNetworkTable->GetNumber("COG_BOX_SIZE");
			double dCogDensity = pNetworkTable->GetNumber("COG_DENSITY");
			double dImageWidth = pNetworkTable->GetNumber("IMAGE_WIDTH");
			double dImageHeight = pNetworkTable->GetNumber("IMAGE_HEIGHT");

			int iLeftVerticalMarker=MARKER_ONE;

			int iRightVerticalMarker = iLeftVerticalMarker + 1;

			// calculate the center point of the image
			double dImageCenterX = dImageWidth / 2.0;
			double dImageCenterY = dImageHeight / 2.0;

			center.x = dImageCenterX;
			center.y = dImageCenterY;

			// Left Rectangle Calculations

			// calculate the distance from the camera to the center of the rect based on calibrarated data and rectangle height
			//double dDistanceLeft_ft = (kCalibratedHeight_px / dMarkerHeights[iLeftVerticalMarker]) * kCalibratedDistance_ft;
		
			// calculate the base in pixels (center of rect to the center of the image)
			//double dLeftCenterX = (rcMarkerRects[iLeftVerticalMarker].ptUR.x + rcMarkerRects[iLeftVerticalMarker].ptUL.x) / 2.0;
			//double dLeftBase = (dImageCenterX - dLeftCenterX);
	

			// Right Rectangle Calculations

			// calculate the distance from the camera to the center of the rect based on calibrarated data and rectangle height
			//double dDistanceRight_ft = (kCalibratedHeight_px / dMarkerHeights[iRightVerticalMarker]) * kCalibratedDistance_ft;

			// calculate the base in pixels (center of rect to the center of the image)
			//double dRightCenterX = (rcMarkerRects[iRightVerticalMarker].ptUR.x + rcMarkerRects[iRightVerticalMarker].ptUL.x) / 2.0;
			// double dRightBase = (dRightCenterX - dImageCenterX);


			// Distance calculations

			// calculate our triangle base length (center of left rect to center of right rect) 
			//double dBaseWidth = dRightCenterX - dLeftCenterX;

			// convert left base from pixels to feet
			//double dLeftBase_ft = (dLeftBase * kdDistanceBetweenReference_ft) / dBaseWidth;

			// calculate the distance, based on other two sides
			//dDistance_ft = sqrt((dDistanceBase_ft*dDistanceBase_ft) + (dHeight_ft*dHeight_ft));
		}
	
		return dDistance_ft;
	}
	catch(...)
	{
	}
	return 0.0;
}
