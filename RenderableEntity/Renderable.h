//
// Created by Марат Гасанов on 22.05.2022.
//

#ifndef EDUCAD_RENDERABLE_H
#define EDUCAD_RENDERABLE_H
#include "string"

class Renderable{
public:
    virtual void addPoint(int x, int y, std::string name) = 0;
    virtual void addLine(int x1, int y1, int x2, int y2, std::string name) = 0;
};


#endif //EDUCAD_RENDERABLE_H