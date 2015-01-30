#include "DistanceTracking.h"

// constants
const double kCalibratedHeight_px			= 100.0;
const double kCalibratedDistance_ft			= 10.0;
const double kdDistanceBetweenReference_ft	= 1.2;
const double k90DegreesInRadians			= 1.57079633;

const int MARKER_ONE = 0;
const int MARKER_TWO = 1;
const int MARKER_THREE = 2;
const int MARKER_FOUR = 3;

const int POINT_UPPER_RIGHT_X = 0;
const int POINT_UPPER_RIGHT_Y = 1;
const int POINT_UPPER_LEFT_X = 2;
const int POINT_UPPER_LEFT_Y = 3;
const int POINT_LOWER_LEFT_X = 4;
const int POINT_LOWER_LEFT_Y = 5;
const int POINT_LOWER_RIGHT_X = 6;
const int POINT_LOWER_RIGHT_Y = 7;

// constructor
DistanceTracking::DistanceTracking() {
}

double DistanceTracking::LawOfCosines(const double & dA, const double & dB, const double & dC) {
	return acos((dA * dA + dB * dB - dC * dC) / (2.0 * dA * dB));
}

int DistanceTracking::GetMarkerData( NumberArray & coords, SPointRect * rcMarkerRects, double * dMarkerHeights /*=NULL*/, double * dMarkerWidths /*=NULL*/ ) {

	try 
	{
		double dUpperCenterY;
		double dLowerCenterY;
		double dLeftCenterX;
		double dRightCenterX;

		int iNumRects = coords.size() / 8;

		SCoordSort * coordOffsets = new SCoordSort[iNumRects];

		for ( int i=0; i<iNumRects; i++ ) {
			coordOffsets[i].dULX = coords.get((i*8)+POINT_UPPER_LEFT_X); coordOffsets[i].iIndex = i*8;
		}

		// iterate for all four rects
		for ( int i=0; i<iNumRects; i++ ) {

			rcMarkerRects[i].ptUR.x = coords.get( coordOffsets[i].iIndex + POINT_UPPER_RIGHT_X );
			rcMarkerRects[i].ptUR.y = coords.get( coordOffsets[i].iIndex + POINT_UPPER_RIGHT_Y );
			rcMarkerRects[i].ptUL.x = coords.get( coordOffsets[i].iIndex + POINT_UPPER_LEFT_X  );
			rcMarkerRects[i].ptUL.y = coords.get( coordOffsets[i].iIndex + POINT_UPPER_LEFT_Y  );
			rcMarkerRects[i].ptLL.x = coords.get( coordOffsets[i].iIndex + POINT_LOWER_LEFT_X  );
			rcMarkerRects[i].ptLL.y = coords.get( coordOffsets[i].iIndex + POINT_LOWER_LEFT_Y  );
			rcMarkerRects[i].ptLR.x = coords.get( coordOffsets[i].iIndex + POINT_LOWER_RIGHT_X );
			rcMarkerRects[i].ptLR.y = coords.get( coordOffsets[i].iIndex + POINT_LOWER_RIGHT_Y );

			if ( dMarkerHeights ) {
				// get the average Y values for the top and bottom of the rect
				dUpperCenterY = (rcMarkerRects[i].ptUL.y + rcMarkerRects[i].ptUR.y) / 2.0;
				dLowerCenterY = (rcMarkerRects[i].ptLL.y + rcMarkerRects[i].ptLR.y) / 2.0;

				// calculate the height, in pixels, of the rect
				dMarkerHeights[i] = dUpperCenterY - dLowerCenterY;
			}

			if ( dMarkerWidths ) {
				// get the average X values for the top and bottom of the rect
				dLeftCenterX = (rcMarkerRects[i].ptUL.x + rcMarkerRects[i].ptLL.x) / 2.0;
				dRightCenterX = (rcMarkerRects[i].ptUR.x + rcMarkerRects[i].ptLR.x) / 2.0;

				// calculate the height, in pixels, of the rect
				dMarkerWidths[i] = dRightCenterX - dLeftCenterX;
			}
		}

		delete coordOffsets;
		coordOffsets = NULL;
	
		return iNumRects;
	}
	catch(...)
	{
	}
	return 0;
}

int DistanceTracking::GetMarkerSizes( NumberArray & coords, double * dMarkerHeights, double * dMarkerWidths, double * dMarkerCenterX ) {

	try 
	{
		int iNumRects = coords.size() / 8;
		
		// iterate for all four rects
		for ( int i=0; i<iNumRects; i++ ) {			
			double dMinX = 100000;
			double dMaxX = -1;
			double dMinY = 100000;
			double dMaxY = -1;
			for ( int j=0; j<4; j++ ) {
				dMinX = (dMinX < coords.get( 8*i + j*2 )) ? dMinX : coords.get( 8*i + j*2 );
				dMaxX = (dMaxX > coords.get( 8*i + j*2 )) ? dMaxX : coords.get( 8*i + j*2 );
				dMinY = (dMinY < coords.get( 8*i + j*2 )) ? dMinX : coords.get( 8*i + j*2 + 1);
				dMaxY = (dMaxY > coords.get( 8*i + j*2 )) ? dMaxX : coords.get( 8*i + j*2 + 1);
			}
			dMarkerWidths[i] = dMaxX - dMinX;
			dMarkerHeights[i] = dMaxY - dMinY;
			dMarkerCenterX[i] = (dMinX + dMaxX) / 2.0;
		}
		return iNumRects;
	}
	catch(...)
	{
	}
	return 0;
}

// get the distance to the wall on the line being aimed at
double DistanceTracking::GetDistanceToTarget() {

	try
	{
		NetworkTable * pNetworkTable		= NetworkTable::GetTable("RoboRealm");
		
		double dDistance_ft = 0.0;
	
		if ( pNetworkTable && pNetworkTable->IsConnected()) {
	
			if ( !pNetworkTable->ContainsKey("COG_X") ||
				 !pNetworkTable->ContainsKey("COG_Y") ||
				 !pNetworkTable->ContainsKey("COG_BOX_SIZE") ||
				 !pNetworkTable->ContainsKey("IMAGE_WIDTH")) {
				return 0.0;
			}

			double		dMarkerHeights[4];
			double		dMarkerWidths[4];
			SPointRect	rcMarkerRects[4];
			double		dDistanceBase_ft = 0.0;
			NumberArray coords;
			SDoublePoint cog;

			cog.x = pNetworkTable->GetNumber("COG_X");
			cog.y = pNetworkTable->GetNumber("COG_Y");
			double dCogWidth = pNetworkTable->GetNumber("COG_BOX_SIZE");
			double dImageWidth = pNetworkTable->GetNumber("IMAGE_WIDTH");

			// gets marker data from the coords data, sorted from left to right
			int iNumRects = GetMarkerData( coords, rcMarkerRects, dMarkerHeights, dMarkerWidths );

			int iLeftVerticalMarker=MARKER_ONE;

			int iRightVerticalMarker = iLeftVerticalMarker + 1;

			// calculate the center point of the image
			double dImageCenterX = dImageWidth / 2.0;
		

			// Left Rectangle Calculations

			// calculate the distance from the camera to the center of the rect based on calibrarated data and rectangle height
			double dDistanceLeft_ft = (kCalibratedHeight_px / dMarkerHeights[iLeftVerticalMarker]) * kCalibratedDistance_ft;
		
			// calculate the base in pixels (center of rect to the center of the image)
			double dLeftCenterX = (rcMarkerRects[iLeftVerticalMarker].ptUR.x + rcMarkerRects[iLeftVerticalMarker].ptUL.x) / 2.0;
			double dLeftBase = (dImageCenterX - dLeftCenterX);
	

			// Right Rectangle Calculations

			// calculate the distance from the camera to the center of the rect based on calibrarated data and rectangle height
			double dDistanceRight_ft = (kCalibratedHeight_px / dMarkerHeights[iRightVerticalMarker]) * kCalibratedDistance_ft;

			// calculate the base in pixels (center of rect to the center of the image)
			double dRightCenterX = (rcMarkerRects[iRightVerticalMarker].ptUR.x + rcMarkerRects[iRightVerticalMarker].ptUL.x) / 2.0;
			// double dRightBase = (dRightCenterX - dImageCenterX);


			// Distance calculations

			// calculate our triangle base length (center of left rect to center of right rect) 
			double dBaseWidth = dRightCenterX - dLeftCenterX;

			// convert left base from pixels to feet
			double dLeftBase_ft = (dLeftBase * kdDistanceBetweenReference_ft) / dBaseWidth;

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

bool DistanceTracking::IsClosestTargetHot() {

	try
	{
		NetworkTable * pNetworkTable = NetworkTable::GetTable("RoboRealm");
	
		if ( pNetworkTable && pNetworkTable->IsConnected()) {

			if ( !pNetworkTable->ContainsKey("COG_X") ||
				 !pNetworkTable->ContainsKey("COG_Y") ||
				 !pNetworkTable->ContainsKey("COG_BOX_SIZE") ||
				 !pNetworkTable->ContainsKey("IMAGE_WIDTH")) {
				return false;
			}

			double		dMarkerHeights[4];
			double		dMarkerWidths[4];
			SPointRect	rcMarkerRects[4];
			double		dDistanceBase_ft = 0.0;
			NumberArray coords;
			SDoublePoint cog;

			cog.x = pNetworkTable->GetNumber("COG_X");
			cog.y = pNetworkTable->GetNumber("COG_Y");
			double dCogWidth = pNetworkTable->GetNumber("COG_BOX_SIZE");
			double dImageWidth = pNetworkTable->GetNumber("IMAGE_WIDTH");

			// call routine to get marker heights (always returns three rect heights)
			int iNumRects = GetMarkerData( coords, rcMarkerRects, dMarkerHeights, dMarkerWidths );
		}
	}
	catch(...)
	{
	}
	return false;
}

bool DistanceTracking::IsAimedTargetHot() {

	try 
	{
		NetworkTable * pNetworkTable = NetworkTable::GetTable("RoboRealm");
	
		// we're assuming that this routine is only called while in autonomous mode
		if ( pNetworkTable && pNetworkTable->IsConnected()) {

			if ( !pNetworkTable->ContainsKey("COG_X") ||
				 !pNetworkTable->ContainsKey("COG_Y") ||
				 !pNetworkTable->ContainsKey("COG_BOX_SIZE") ||
				 !pNetworkTable->ContainsKey("IMAGE_WIDTH")) {
				countNoTable++;
				return false;
			}


			double		dMarkerHeights[4];
			double		dMarkerWidths[4];
			SPointRect	rcMarkerRects[4];
			double		dDistanceBase_ft = 0.0;
			NumberArray coords;
			SDoublePoint cog;

			cog.x = pNetworkTable->GetNumber("COG_X");
			cog.y = pNetworkTable->GetNumber("COG_Y");
			double dCogWidth = pNetworkTable->GetNumber("COG_BOX_SIZE");
			double dImageWidth = pNetworkTable->GetNumber("IMAGE_WIDTH");

			double dImageCenterX = dImageWidth / 2.0;
		}
	}
	catch(...)
	{
		return false;
	}
	return false;
}
