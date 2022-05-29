//
// Created by Марат Гасанов on 29.05.2022.
//

#include "Algo.h"

AngemPoint getMiddle(AngemPoint p1, AngemPoint p2){
    AngemPoint middle;
    middle.x = abs(p1.x - p2.x)/2;
    middle.y = abs(p1.y - p2.y)/2;
    middle.z = abs(p1.z - p2.z)/2;
    return middle;
}

algorithm<TwoDEntity> Algo::pointOnPlaneProjection(PTR<Point> point, PTR<Plane> plane) {
    PTR<ProjectionPlane> projectionPlane;
    PTR<ProjectionPlane> projectionPlane2;
    for(auto &it:point->projections){
        projectionPlane = it;
        break;
    }

    for (auto it:plane->projections) {
        if (it == projectionPlane){
            continue;
        }
        else{
            projectionPlane2 = it;
            break;
        }
    }
    PTR<Point> point1;
    PTR<Point> point2;
    PTR<Line> line;
    if (plane->planeType() == "planeByPointAndLine"){
        PTR<PlaneByPointAndLine> planeByPointAndLine = std::dynamic_pointer_cast<PlaneByPointAndLine>(plane);
        point1 = planeByPointAndLine->point;
        line = MAKEPTR<LineByTwoPoints>(point1, point);
        AngemPoint point2Coords = AngemUtils::linesIntersection(*line, *planeByPointAndLine->line);
        point2 = MAKEPTR<PointByCoords>(point2Coords.x, point2Coords.y, point2Coords.z);
    }
    algorithm<TwoDEntity> alg;
    PTR<TwoDEntity> lineProjection1 = line->getProjection(projectionPlane);
    lineProjection1->projectedEntity = line;
    lineProjection1->projectionPlane = projectionPlane;

    PTR<TwoDEntity> point2Projection1 = point2->getProjection(projectionPlane);
    point2Projection1->projectedEntity = point2;
    point2Projection1->projectionPlane = projectionPlane;

    PTR<TwoDEntity> point2Projection2 = point2->getProjection(projectionPlane2);
    point2Projection2->projectedEntity = point2;
    point2Projection2->projectionPlane = projectionPlane2;

    PTR<TwoDEntity> lineProjection2 = line->getProjection(projectionPlane2);
    lineProjection2->projectedEntity = line;
    lineProjection2->projectionPlane = projectionPlane2;

    PTR<TwoDEntity> pointProjection = point2->getProjection(projectionPlane2);
    pointProjection->projectedEntity = point2;
    pointProjection->projectionPlane = projectionPlane2;

    alg.push_back({"Строим прямую из точки на плоскости к искомой точке", {lineProjection1}});
    alg.push_back({"Находим пересечение с прямой на плоскости", {point2Projection1}});
    alg.push_back({"Находим проекцию этой точки на другую плоскость", {point2Projection2}});
    alg.push_back( { "Строим прямую из двух точек", {lineProjection2}});
    alg.push_back( { "Находим проекцию точки на прямой", {pointProjection}});

    return alg;
}