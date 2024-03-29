/*
    Copyright 2011 Google Inc.

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at

         http://www.apache.org/licenses/LICENSE-2.0

    Unless required by applicable law or agreed to in writing, software
    distributed under the License is distributed on an "AS IS" BASIS,
    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
    See the License for the specific language governing permissions and
    limitations under the License.
 */

#include "GrPathUtils.h"

#include "GrPathIter.h"
#include "GrPoint.h"

const GrScalar GrPathUtils::gTolerance = GR_Scalar1;

static const uint32_t MAX_POINTS_PER_CURVE = 1 << 10;

uint32_t GrPathUtils::quadraticPointCount(const GrPoint points[],
                                             GrScalar tol) {
    GrScalar d = points[1].distanceToLineSegmentBetween(points[0], points[2]);
    if (d < tol) {
        return 1;
    } else {
        // Each time we subdivide, d should be cut in 4. So we need to
        // subdivide x = log4(d/tol) times. x subdivisions creates 2^(x)
        // points.
        // 2^(log4(x)) = sqrt(x);
        d = ceilf(sqrtf(d/tol));
        return GrMin(GrNextPow2((uint32_t)d), MAX_POINTS_PER_CURVE);
    }
}

uint32_t GrPathUtils::generateQuadraticPoints(const GrPoint& p0,
                                                 const GrPoint& p1,
                                                 const GrPoint& p2,
                                                 GrScalar tolSqd,
                                                 GrPoint** points,
                                                 uint32_t pointsLeft) {
    if (pointsLeft < 2 ||
        (p1.distanceToLineSegmentBetweenSqd(p0, p2)) < tolSqd) {
        (*points)[0] = p2;
        *points += 1;
        return 1;
    }

    GrPoint q[] = {
        GrPoint(GrScalarAve(p0.fX, p1.fX), GrScalarAve(p0.fY, p1.fY)),
        GrPoint(GrScalarAve(p1.fX, p2.fX), GrScalarAve(p1.fY, p2.fY)),
    };
    GrPoint r(GrScalarAve(q[0].fX, q[1].fX), GrScalarAve(q[0].fY, q[1].fY));

    pointsLeft >>= 1;
    uint32_t a = generateQuadraticPoints(p0, q[0], r, tolSqd, points, pointsLeft);
    uint32_t b = generateQuadraticPoints(r, q[1], p2, tolSqd, points, pointsLeft);
    return a + b;
}

uint32_t GrPathUtils::cubicPointCount(const GrPoint points[],
                                           GrScalar tol) {
    GrScalar d = GrMax(points[1].distanceToLineSegmentBetweenSqd(points[0], points[3]),
                       points[2].distanceToLineSegmentBetweenSqd(points[0], points[3]));
    d = sqrtf(d);
    if (d < tol) {
        return 1;
    } else {
        d = ceilf(sqrtf(d/tol));
        return GrMin(GrNextPow2((uint32_t)d), MAX_POINTS_PER_CURVE);
    }
}

uint32_t GrPathUtils::generateCubicPoints(const GrPoint& p0,
                                             const GrPoint& p1,
                                             const GrPoint& p2,
                                             const GrPoint& p3,
                                             GrScalar tolSqd,
                                             GrPoint** points,
                                             uint32_t pointsLeft) {
    if (pointsLeft < 2 ||
        (p1.distanceToLineSegmentBetweenSqd(p0, p3) < tolSqd &&
         p2.distanceToLineSegmentBetweenSqd(p0, p3) < tolSqd)) {
            (*points)[0] = p3;
            *points += 1;
            return 1;
        }
    GrPoint q[] = {
        GrPoint(GrScalarAve(p0.fX, p1.fX), GrScalarAve(p0.fY, p1.fY)),
        GrPoint(GrScalarAve(p1.fX, p2.fX), GrScalarAve(p1.fY, p2.fY)),
        GrPoint(GrScalarAve(p2.fX, p3.fX), GrScalarAve(p2.fY, p3.fY))
    };
    GrPoint r[] = {
        GrPoint(GrScalarAve(q[0].fX, q[1].fX), GrScalarAve(q[0].fY, q[1].fY)),
        GrPoint(GrScalarAve(q[1].fX, q[2].fX), GrScalarAve(q[1].fY, q[2].fY))
    };
    GrPoint s(GrScalarAve(r[0].fX, r[1].fX), GrScalarAve(r[0].fY, r[1].fY));
    pointsLeft >>= 1;
    uint32_t a = generateCubicPoints(p0, q[0], r[0], s, tolSqd, points, pointsLeft);
    uint32_t b = generateCubicPoints(s, r[1], q[2], p3, tolSqd, points, pointsLeft);
    return a + b;
}

int GrPathUtils::worstCasePointCount(GrPathIter* path,
                                        int* subpaths,
                                        GrScalar tol) {
    int pointCount = 0;
    *subpaths = 1;

    bool first = true;

    GrPathCmd cmd;

    GrPoint pts[4];
    while ((cmd = path->next(pts)) != kEnd_PathCmd) {

        switch (cmd) {
            case kLine_PathCmd:
                pointCount += 1;
                break;
            case kQuadratic_PathCmd:
                pointCount += quadraticPointCount(pts, tol);
                break;
            case kCubic_PathCmd:
                pointCount += cubicPointCount(pts, tol);
                break;
            case kMove_PathCmd:
                pointCount += 1;
                if (!first) {
                    ++(*subpaths);
                }
                break;
            default:
                break;
        }
        first = false;
    }
    return pointCount;
}
