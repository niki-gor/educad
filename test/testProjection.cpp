//
// Created by Марат Гасанов on 27.05.2022.
//
#include "Entity.hpp"
#include "gtest/gtest.h"

PTR<ProjectionPlane> oxy(new ProjectionPlane(0,0,1,0));
PTR<ProjectionPlane> oxz(new ProjectionPlane(0,1,0,0));
PTR<Point> point(new PointByCoords(1,1,1));
PTR<Point> point2(new PointByCoords(100, 100, 100));
PTR<Line> line(new LineByTwoPoints(point, point2));

TEST(plane, onRightAbscissAndOrdinat){
    EXPECT_EQ(0, oxy->absciss->point1->x);
    EXPECT_EQ(0, oxy->absciss->point1->y);
    EXPECT_EQ(0, oxy->absciss->point1->z);
    EXPECT_EQ(1, oxy->absciss->point2->x);
    EXPECT_EQ(0, oxy->absciss->point2->y);
    EXPECT_EQ(0, oxy->absciss->point1->z);

    EXPECT_EQ(0, oxy->ordinat->point1->x);
    EXPECT_EQ(0, oxy->ordinat->point1->y);
    EXPECT_EQ(0, oxy->ordinat->point1->z);
    EXPECT_EQ(0, oxy->ordinat->point2->x);
    EXPECT_EQ(1, oxy->ordinat->point2->y);
    EXPECT_EQ(0, oxy->ordinat->point2->z);

    EXPECT_EQ(0, oxz->absciss->point1->x);
    EXPECT_EQ(0, oxz->absciss->point1->y);
    EXPECT_EQ(0, oxz->absciss->point1->z);
    EXPECT_EQ(1, oxz->absciss->point2->x);
    EXPECT_EQ(0, oxz->absciss->point2->y);
    EXPECT_EQ(0, oxz->absciss->point2->z);

    EXPECT_EQ(0, oxz->ordinat->point1->x);
    EXPECT_EQ(0, oxz->ordinat->point1->y);
    EXPECT_EQ(0, oxz->ordinat->point1->z);
    EXPECT_EQ(0, oxz->ordinat->point2->x);
    EXPECT_EQ(1, oxz->ordinat->point2->z);
    EXPECT_EQ(0, oxz->ordinat->point2->y);

}

TEST(coords, Point1Projection){
    PTR<TwoDPoint> oxyProjection = point->getProjectionPoint(oxy);
    PTR<TwoDPoint> oxzProjection = point->getProjectionPoint(oxz);
    EXPECT_EQ(1, oxyProjection->X);
    EXPECT_EQ(1, oxyProjection->Y);

    EXPECT_EQ(1, oxyProjection->X);
    EXPECT_EQ(1, oxzProjection->Y);
}

TEST(coords, Point2Projection){
    PTR<TwoDPoint> oxyProjection = point2->getProjectionPoint(oxy);
    PTR<TwoDPoint> oxzProjection = point2->getProjectionPoint(oxz);
    EXPECT_EQ(100, oxyProjection->X);
    EXPECT_EQ(100, oxyProjection->Y);

    EXPECT_EQ(100, oxyProjection->X);
    EXPECT_EQ(100, oxzProjection->Y);
}

TEST(coords, LineOnProjection){
    PTR<TwoDLine> oxyProjection = line->getProjectionLine(oxy);
    PTR<TwoDLine> oxzProjection = line->getProjectionLine(oxz);
    EXPECT_EQ(1, oxyProjection->point1->X);
    EXPECT_EQ(1, oxyProjection->point1->Y);

    EXPECT_EQ(100, oxyProjection->point2->X);
    EXPECT_EQ(100, oxyProjection->point2->Y);

    EXPECT_EQ(1, oxzProjection->point1->X);
    EXPECT_EQ(1, oxzProjection->point1->Y);

    EXPECT_EQ(100, oxzProjection->point2->X);
    EXPECT_EQ(100, oxzProjection->point2->Y);
}

TEST(parent, PareentOnEntity){
    PTR<TwoDEntity> oxyProjectionLine = line->getProjection(oxy);
    PTR<TwoDEntity> oxzProjectionLine = line->getProjection(oxz);
    PTR<TwoDEntity> oxyProjectionPoint1 = point->getProjection(oxy);
    PTR<TwoDEntity> oxzProjectionPoint1 = point->getProjection(oxz);
    PTR<TwoDEntity> oxyProjectionPoint2 = point2->getProjection(oxy);
    PTR<TwoDEntity> oxzProjectionPoint2 = point2->getProjection(oxz);

    EXPECT_EQ(point, oxyProjectionPoint1->projectedEntity);
    EXPECT_EQ(point, oxyProjectionPoint1->projectedEntity);

    EXPECT_EQ(point2, oxyProjectionPoint2->projectedEntity);
    EXPECT_EQ(point2, oxyProjectionPoint2->projectedEntity);

    EXPECT_EQ(line, oxyProjectionLine->projectedEntity);
    EXPECT_EQ(line, oxyProjectionLine->projectedEntity);
}