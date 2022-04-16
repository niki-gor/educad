#ifndef DRAWINGSPACE_H
#define DRAWINGSPACE_H

#include "canvas.h"
#include "QImage"

class DescriptiveSpace
{
private:
    Canvas* fieldXZ;
    Canvas* fieldXY;
public:
    QImage getXZIm () {return fieldXZ->im;}
    QImage getXYIm () {return fieldXY->im;}
    DescriptiveSpace();
};

#endif // DRAWINGSPACE_H
