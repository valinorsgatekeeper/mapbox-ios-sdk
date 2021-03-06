//
//  RMFoundation.h
//
// Copyright (c) 2008-2009, Route-Me Contributors
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice, this
//   list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the following disclaimer in the documentation
//   and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

#ifndef _RMFOUNDATION_H_
#define _RMFOUNDATION_H_

#include <stdbool.h>

#if __OBJC__
#import <CoreLocation/CoreLocation.h>
#endif

/*! \struct RMProjectedPoint 
 \brief coordinates, in projected meters, paralleling CGPoint */
typedef struct {
	double x, y;
} RMProjectedPoint;

/*! \struct RMProjectedSize 
 \brief width/height struct, in projected meters, paralleling CGSize */
typedef struct {
	double width, height;
} RMProjectedSize;

/*! \struct RMProjectedRect 
 \brief location and size, in projected meters, paralleling CGRect */
typedef struct {
	RMProjectedPoint origin;
	RMProjectedSize size;
} RMProjectedRect;

#if __OBJC__
/*! \struct RMSphericalTrapezium
 \brief a rectangle, specified by two corner coordinates */
typedef struct {
	CLLocationCoordinate2D southWest;
	CLLocationCoordinate2D northEast;
} RMSphericalTrapezium;
#endif

RMProjectedPoint RMScaleProjectedPointAboutPoint(RMProjectedPoint point, float factor, RMProjectedPoint pivot);
RMProjectedRect  RMScaleProjectedRectAboutPoint(RMProjectedRect rect, float factor, RMProjectedPoint pivot);
RMProjectedPoint RMTranslateProjectedPointBy(RMProjectedPoint point, RMProjectedSize delta);
RMProjectedRect  RMTranslateProjectedRectBy(RMProjectedRect rect, RMProjectedSize delta);

/// \brief The function checks whether two passed projected points are equal.
bool RMProjectedPointEqualToProjectedPoint(RMProjectedPoint point1, RMProjectedPoint point2);

/// \brief The function returs true if the passed rects intersect each other.
bool RMProjectedRectIntersectsProjectedRect(RMProjectedRect rect1, RMProjectedRect rect2);

/// \brief The function returns true if rect1 contains rect2
bool RMProjectedRectContainsProjectedRect(RMProjectedRect rect1, RMProjectedRect rect2);

// Union of two rectangles
RMProjectedRect RMProjectedRectUnion(RMProjectedRect rect1, RMProjectedRect rect2);

RMProjectedPoint RMProjectedPointMake(double x, double y);
RMProjectedRect  RMProjectedRectMake(double x, double y, double width, double height);
RMProjectedSize  RMProjectedSizeMake(double width, double heigth);

RMProjectedRect RMProjectedRectZero();
bool RMProjectedRectIsZero(RMProjectedRect rect);

double RMEuclideanDistanceBetweenProjectedPoints(RMProjectedPoint point1, RMProjectedPoint point2);

#endif
