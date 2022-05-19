//
// Created by Марат Гасанов on 15.04.2022.
//

#include "TwoDEntity.h"
#include "iostream"

TwoDLine::TwoDLine(const std::shared_ptr<TwoDPoint>& point1, const std::shared_ptr<TwoDPoint>& point2, PTR<ProjectionPlane> plane) {
   this->point1 = point1;
   this->point2 = point2;
   this->projectionPlane = plane;
   A = 1/(point2->X - point1->X);
   B = 1/(point2->Y - point1->Y);
   C = -(point1->X/(point2->X - point1->X)) + (point1->Y/(point2->Y - point1->Y));

}

void TwoDLine::render() {
    std::cout << "Render line: " << A << "x + " << B << "y + " << C << " = 0" << std::endl;
}

