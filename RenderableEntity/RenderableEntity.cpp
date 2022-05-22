//
// Created by Марат Гасанов on 22.05.2022.
//

#include "RenderableEntity.h"

void RenderablePoint::render(Canvas* canvas) {
    canvas->addPoint(this->X, this->Y, "uzbek");
}

void RenderableLine::render(Canvas* canvas) {
    canvas->addLine(this->point1->X, this->point1->Y, this->point2->X, this->point2->Y);
}
