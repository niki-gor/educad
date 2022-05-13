//
// Created by Марат Гасанов on 13.05.2022.
//

#ifndef EDUCAD_CONTROLLEROBSERVABLE_H
#define EDUCAD_CONTROLLEROBSERVABLE_H
#include "TwoDEntity.h"

class ControllerObservable{
public:
    virtual void onAddEntity(PTR<Entity> entity) = 0;
    virtual void onDeleteEntity(PTR<Entity> entity) = 0;
};

#endif //EDUCAD_CONTROLLEROBSERVABLE_H
