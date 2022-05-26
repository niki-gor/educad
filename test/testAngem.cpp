#include <gtest/gtest.h>
#include "Angem.hpp"
#include "Entity.hpp"
#include <vector>

template<typename Float> 
bool equals(const Float lVal, const Float rVal)
{
    //static Float ep = std::numeric_limits<Float>::epsilon();
    static Float ep = 10e-8;
    const Float diff = fabs(lVal - rVal);
    return diff < ep;
}

void EXPECT_D_EQ(double const & lhs, double const & rhs){
    EXPECT_TRUE(equals(lhs, rhs));
}

TEST(AngemUtils, getPerpendicularToLines)
{
    PTR<Point> A(new PointByCoords(8, 6, 0));
    PTR<Point> B(new PointByCoords(6, 3, 0));
    PTR<Point> C(new PointByCoords(2, 10, 0));
    LineByTwoPoints l1 = LineByTwoPoints(A,B);
    LineByTwoPoints l2 = LineByTwoPoints(A,C);
    AngemLine lr = AngemUtils::getPerpendicularLine(l1, l2);

    EXPECT_D_EQ(lr.i, 0.);
    EXPECT_D_EQ(lr.j, 0.);
    EXPECT_D_EQ(lr.k, -26);
    EXPECT_D_EQ(lr.x0, 8);
    EXPECT_D_EQ(lr.y0, 6);
    EXPECT_D_EQ(lr.z0, 0);
}

TEST(AngemUtils, getPerpendicularFromPointToLine)
{
    PTR<Point> A(new PointByCoords(1, 2, 3));
    PTR<Point> B(new PointByCoords(-4, 2, 0));
    PointByCoords C = PointByCoords(1, 1, 1);
    LineByTwoPoints l1 = LineByTwoPoints(A,B);
    AngemLine lr = AngemUtils::getPerpendicularLine(C,l1);
    
    EXPECT_D_EQ(lr.i, 0.88235294117647056);
    EXPECT_D_EQ(lr.j, -1.);
    EXPECT_D_EQ(lr.k, -1.4705882352941178);
    EXPECT_D_EQ(lr.x0, 1);
    EXPECT_D_EQ(lr.y0, 1);
    EXPECT_D_EQ(lr.z0, 1);
}

TEST(AngemUtils, getPerpendicularFromPointToPlane)
{
    PTR<Point> A(new PointByCoords(8, 6, 0));
    PTR<Point> B(new PointByCoords(6, 3, 0));
    PTR<Point> C(new PointByCoords(2, 11, 1));
    PlaneByThreePoints pl = PlaneByThreePoints(A,B,C);
    PointByCoords D = PointByCoords(7, 8 , 10);
    AngemLine lr = AngemUtils::getPerpendicularLine(D, pl);
    EXPECT_D_EQ(lr.i, -3);
    EXPECT_D_EQ(lr.j, 2);
    EXPECT_D_EQ(lr.k, -28);
    EXPECT_D_EQ(lr.x0, 7);
    EXPECT_D_EQ(lr.y0, 8);
    EXPECT_D_EQ(lr.z0, 10);
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
    EXPECT_D_EQ(pIntersection.x, C->x);
    EXPECT_D_EQ(pIntersection.y, C->y);
    EXPECT_D_EQ(pIntersection.z, C->z);
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
    EXPECT_D_EQ(lr.i, -273);
    EXPECT_D_EQ(lr.j, 546);
    EXPECT_D_EQ(lr.k, 2730);
}

TEST(AngemUtils, parallelLine)
{
    PTR<Point> A(new PointByCoords(8, 6, 0));
    PTR<Point> C(new PointByCoords(2, 11, 1));
    PTR<Point> D(new PointByCoords(7, 8 , 10));
    LineByTwoPoints l1 = LineByTwoPoints(A,D);
    AngemLine lr = AngemUtils::parallelLine(l1, *C);
    EXPECT_D_EQ(lr.i, l1.i);
    EXPECT_D_EQ(lr.j, l1.j);
    EXPECT_D_EQ(lr.k, l1.k);
}

TEST(AngemUtils, Determinant)
{
    matrix matr = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    double det = AngemUtils::getDeterminant(matr);
    EXPECT_D_EQ(det, 0);
    matr = {
        {1,10,3},
        {4,5,6},
        {7,8,9}
    };
    det = AngemUtils::getDeterminant(matr);
    EXPECT_D_EQ(det, 48);
    
}

TEST(AngemUtils, getDistanceFromPointToLine)
{
    AngemPoint M(0,2,3);
    AngemLine l(2,1,2,3,1,-1);
    double dist = AngemUtils::getDistance(M, l);
    EXPECT_D_EQ(dist,5);
}

TEST(AngemUtils, getDistanceFromPointToPlane)
{
    AngemPlane pl(2, 4, -4, -6);
    AngemPoint p(0, 3, 6);
    double dist = AngemUtils::getDistance(p, pl);
    EXPECT_D_EQ(dist,3);
}

TEST(AngemUtils, linePlaneIntersection)
{
    PTR<Point> A(new PointByCoords(1,3,4));
    PTR<Point> B(new PointByCoords(4,3,1));
    PTR<Point> C(new PointByCoords(-2,1,-3));
    PTR<Point> D(new PointByCoords(2,-4,2));
    PlaneByThreePoints pl = PlaneByThreePoints(A, B,C);
    LineByTwoPoints l = LineByTwoPoints(D,B);
    AngemPoint p = AngemUtils::planeLineIntersection(pl, l);
    EXPECT_D_EQ(p.x, B->x);
    EXPECT_D_EQ(p.y, B->y);
    EXPECT_D_EQ(p.z, B->z);
}


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}