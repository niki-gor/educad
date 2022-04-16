#ifndef IGUIOBSERVER_H
#define IGUIOBSERVER_H
#include "TwoDEntity/TwoDEntity.h"
#include "Entity/Entity.hpp"

#include <memory>

class IGUIObserver {
    virtual int onCreate () = 0;
    virtual int onChange () = 0;
    virtual int onDelete () = 0;
    virtual ~IGUIObserver();
};

class IGUIPointObserver  {
    int onCreate (std::shared_ptr<ProjectionPlane> plane, std::shared_ptr<TwoDEntity> object);
    int onChange (std::shared_ptr<ProjectionPlane> plane, std::shared_ptr<TwoDEntity> oldObject, std::shared_ptr<TwoDEntity> newObject);
    int onDelete (std::shared_ptr<ProjectionPlane> plane, std::shared_ptr<TwoDEntity> object);
};

class IGUILineObserver {
    int onCreate (std::shared_ptr<ProjectionPlane> plane, std::shared_ptr<TwoDEntity> object);
    int onChange (std::shared_ptr<ProjectionPlane> plane, std::shared_ptr<TwoDEntity> oldObject, std::shared_ptr<TwoDEntity> newObject);
    int onDelete (std::shared_ptr<ProjectionPlane> plane, std::shared_ptr<TwoDEntity> object);
};

class IGUIPlaneObserver {
    int onCreate (std::shared_ptr<ProjectionPlane> plane, std::shared_ptr<TwoDEntity> object);
    int onChange (std::shared_ptr<ProjectionPlane> plane, std::shared_ptr<TwoDEntity> oldObject, std::shared_ptr<TwoDEntity> newObject);
    int onDelete (std::shared_ptr<ProjectionPlane> plane, std::shared_ptr<TwoDEntity> object);
};

class IGUIUserPointObserver {
    int onCreate ();
    int onChange ();
    int onDelete ();
};


class IGUIUserLineObserver {
    int onCreate ();
    int onChange ();
    int onDelete ();
};


class IGUIUserPlaneObserver {
    int onCreate ();
    int onChange ();
    int onDelete ();
};

#endif // IGUIOBSERVER_H
