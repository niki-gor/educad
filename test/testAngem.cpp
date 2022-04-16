#include <gtest/gtest.h>
#include "Angem.hpp"


TEST(AngemUtils, getPerpendicularToLine)
{
    PTR<Point> A(new PointByCoords(8, 6, 0));
    PTR<Point> B(new PointByCoords(6, 3, 0));
    PTR<Point> C(new PointByCoords(2, 10, 0));
    LineByTwoPoints l1 = LineByTwoPoints(A,B);
    LineByTwoPoints l1 = LineByTwoPoints(A,C);
    AngemUtils::getPerpendicularLine();
}

TEST(AngemUtils, )


int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}