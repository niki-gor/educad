//
// Created by Марат Гасанов on 15.04.2022.
//

#include "TwoDLine.h"
#include "iostream"

TwoDLine::TwoDLine(const std::shared_ptr<TwoDPoint>& point1, const std::shared_ptr<TwoDPoint>& point2) {
   this->point1 = point1;
   this->point2 = point2;
   a = 1/(point2->x - point1->x);
   b = 1/(point2->y - point1->y);
   c = -(point1->x/(point2->x - point1->x)) + (point1->y/(point2->y - point1->y));
}

void TwoDLine::render() {
    std::cout << "Render line: " << a << "x + " << b << "y + " << c << " = 0" << std::endl;
}

