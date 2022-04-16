#pragma once

#include "Entity.hpp"
#include "Utils.hpp"



namespace Algo {
    bool getProjection(PTR<ProjectionPlane>, PTR<Entity>);
    bool getIntersection(PTR<ProjectionPlane>, PTR<Line>, PTR<Line>);
    bool getParallelLine(PTR<ProjectionPlane>, PTR<Point>, PTR<Line>);
    bool getPerpendicular(PTR<ProjectionPlane>, PTR<Point>, PTR<Line>);
    bool getPerpendicular(PTR<ProjectionPlane>, PTR<Point>, PTR<Plane>);
    bool getLine(PTR<ProjectionPlane>, PTR<Point>, PTR<Point>);
    bool getLine(PTR<ProjectionPlane>, PTR<Plane>, PTR<Plane>);
    bool getPlane(PTR<ProjectionPlane>, PTR<Point>, PTR<Point>, PTR<Point>);
    bool getPlane(PTR<ProjectionPlane>, PTR<Point>, PTR<Line>);
    bool getPlane(PTR<ProjectionPlane>, PTR<Line>, PTR<Line>);
    bool getRealLength(PTR<ProjectionPlane>, PTR<Point>, PTR<Point>);
    bool getSteepestLine(PTR<ProjectionPlane>, PTR<Plane>);
};