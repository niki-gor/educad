#include <gtest/gtest.h>
#include "Angem.hpp"
#include "Entity.hpp"


TEST(AngemUtils, getPerpendicularToLines)
{
    PTR<Point> A(new PointByCoords(8, 6, 0));
    PTR<Point> B(new PointByCoords(6, 3, 0));
    PTR<Point> C(new PointByCoords(2, 10, 0));
    LineByTwoPoints l1 = LineByTwoPoints(A,B);
    LineByTwoPoints l2 = LineByTwoPoints(A,C);
    AngemLine lr = AngemUtils::getPerpendicularLine(l1, l2);

    EXPECT_DOUBLE_EQ(lr.i, 0.);
    EXPECT_DOUBLE_EQ(lr.j, 0.);
    EXPECT_DOUBLE_EQ(lr.k, -26);
    EXPECT_DOUBLE_EQ(lr.x0, 8);
    EXPECT_DOUBLE_EQ(lr.y0, 6);
    EXPECT_DOUBLE_EQ(lr.z0, 0);
}
TEST(AngemUtils, getPerpendicularFromPointToLine)
{
    PTR<Point> A(new PointByCoords(1, 2, 3));
    PTR<Point> B(new PointByCoords(-4, 2, 0));
    PointByCoords C = PointByCoords(1, 1, 1);
    LineByTwoPoints l1 = LineByTwoPoints(A,B);
    AngemLine lr = AngemUtils::getPerpendicularLine(C,l1);
    EXPECT_DOUBLE_EQ(lr.i, 0.88);
    EXPECT_DOUBLE_EQ(lr.j, -1.);
    EXPECT_DOUBLE_EQ(lr.k, -1.47);
    EXPECT_DOUBLE_EQ(lr.x0, 1);
    EXPECT_DOUBLE_EQ(lr.y0, 1);
    EXPECT_DOUBLE_EQ(lr.z0, 1);
}

TEST(AngemUtils, getPerpendicularFromPointToPlane)
{
    PTR<Point> A(new PointByCoords(8, 6, 0));
    PTR<Point> B(new PointByCoords(6, 3, 0));
    PTR<Point> C(new PointByCoords(2, 11, 1));
    PlaneByThreePoints pl = PlaneByThreePoints(A,B,C);
    PointByCoords D = PointByCoords(7, 8 , 10);
    AngemLine lr = AngemUtils::getPerpendicularLine(D, pl);
    EXPECT_DOUBLE_EQ(lr.i, -3);
    EXPECT_DOUBLE_EQ(lr.j, 2);
    EXPECT_DOUBLE_EQ(lr.k, -28);
    EXPECT_DOUBLE_EQ(lr.x0, 7);
    EXPECT_DOUBLE_EQ(lr.y0, 8);
    EXPECT_DOUBLE_EQ(lr.z0, 10);
}

TEST(AngemUtils,linesIntersection)
{
    PTR<Point> A(new PointByCoords(8, 6, 0));
    PTR<Point> C(new PointByCoords(2, 11, 1));
    PTR<Point> E(new PointByCoords(5, 9.2 , 6.4));
    PTR<Point> D(new PointByCoords(7, 8 , 10));
    LineByTwoPoints l1 = LineByTwoPoints(A,C);
    LineByTwoPoints l2 = LineByTwoPoints(D,E);
    AngemPoint pIntersection = AngemUtils::linesIntersection(l1,l2);
    EXPECT_DOUBLE_EQ(pIntersection.x, C->x);
    EXPECT_DOUBLE_EQ(pIntersection.y, C->y);
    EXPECT_DOUBLE_EQ(pIntersection.z, C->z);
}

TEST(AngemUtils, planesIntersection)
{
    PTR<Point> A(new PointByCoords(8, 6, 0));
    PTR<Point> C(new PointByCoords(2, 11, 1));
    PTR<Point> D(new PointByCoords(7, 8 , 10));
    PTR<Point> B(new PointByCoords(6, 3, 0));
    PlaneByThreePoints pl1 = PlaneByThreePoints(A,D,C);
    PlaneByThreePoints pl2 = PlaneByThreePoints(A,D,B);
    AngemLine lr =  AngemUtils::planesIntersection(pl1, pl2);
    LineByTwoPoints l1 = LineByTwoPoints(A,D);
    EXPECT_DOUBLE_EQ(lr.i, l1.i);
    EXPECT_DOUBLE_EQ(lr.j, l1.j);
    EXPECT_DOUBLE_EQ(lr.k, l1.k);
}

TEST(AngemUtils, parallelLine)
{
    PTR<Point> A(new PointByCoords(8, 6, 0));
    PTR<Point> C(new PointByCoords(2, 11, 1));
    PTR<Point> D(new PointByCoords(7, 8 , 10));
    LineByTwoPoints l1 = LineByTwoPoints(A,D);
    AngemLine lr = AngemUtils::parallelLine(l1, *C);
    EXPECT_DOUBLE_EQ(lr.i, l1.i);
    EXPECT_DOUBLE_EQ(lr.j, l1.j);
    EXPECT_DOUBLE_EQ(lr.k, l1.k);
}



int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}