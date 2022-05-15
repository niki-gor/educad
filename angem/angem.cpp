#include "angem.h"



Position2D AngemPoint2D::getPosition() const {
    return position;
}

LineEquation2D AngemLine2D::getEquation() const {
    return equation;
}

PlaneEquation3D AngemPlane3D::getEquation() const {
    return equation;
}

CirclePosition2D AngemCircle2D::getPosition() const {
    return position;
}

SpherePosition3D AngemSphere3D::getPosition() const {
    return position;
}