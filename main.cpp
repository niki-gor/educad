#include "point2d.h"
#include "line2d.h"



int main() {
    PTR<Point2D> e1;
    PTR<Point2D> e2;
    PTR<Entity2D> entity(MAKEPTR<Line2DbyTwoPoints>(e1, e2));
    return 0;
}