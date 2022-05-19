#include "canvas.h"
#include "iguiobserver.h"
#include "TwoDEntity/TwoDEntity.h"



int IGUIPointObserver::onCreate (std::shared_ptr<TwoDPoint> object) {
    canvas->addPoint(object->X, object->Y, "sus");
    return 0;
}

int IGUILineObserver::onCreate(std::shared_ptr<TwoDLine> object) {
    canvas->addLine(object->point1->X, object->point1->Y, object->point2->X, object->point2->Y, "sus");
}
