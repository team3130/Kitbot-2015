#ifndef DISTANCE_TRACKING_H
#define DISTANCE_TRACKING_H

#include "WPILib.h"

class DistanceTracking {

typedef struct SDoublePoint {
	double x;
	double y;
} SDoublePoint;

typedef struct SPointRect {
	SDoublePoint ptUL;
	SDoublePoint ptUR;
	SDoublePoint ptLR;
	SDoublePoint ptLL;
} SPointRect;

public:
				DistanceTracking();
	double 		GetDistanceToTarget();
};

#endif
