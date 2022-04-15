//
// Created by Марат Гасанов on 15.04.2022.
//

#ifndef RENDER_ANGEMENTITY_H
#define RENDER_ANGEMENTITY_H
#include "../../TwoDObject/TwoDObject.h"
#include "../../ProjectionPlane/ProjectionPlane.h"

class AngemEntity{
public:
    virtual std::shared_ptr<TwoDObject> getTwoDObject(std::shared_ptr<ProjectionPlane>) = 0;
};

#endif //RENDER_ANGEMENTITY_H

