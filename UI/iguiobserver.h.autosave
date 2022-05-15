#ifndef IGUIOBSERVER_H
#define IGUIOBSERVER_H
#include "canvas.h"
#include "TwoDEntity/TwoDEntity.h"
#include <memory>

class IGUIObserver {
protected:
    Canvas* canvas;
};

class IGUIPointObserver : public IGUIObserver {
   // int onChange (std::shared_ptr<ProjectionPlane> plane, std::shared_ptr<TwoDEntity> oldObject, std::shared_ptr<TwoDEntity> newObject);
   // int onDelete (std::shared_ptr<ProjectionPlane> plane, std::shared_ptr<TwoDEntity> object);
public:
    int onCreate (std::shared_ptr<TwoDPoint> object);
    IGUIPointObserver(Canvas* _canvas) {canvas=_canvas;}
    ~IGUIPointObserver();
};

class IGUILineObserver : public IGUIObserver {
   // int onChange (std::shared_ptr<ProjectionPlane> plane, std::shared_ptr<TwoDEntity> oldObject, std::shared_ptr<TwoDEntity> newObject);
  //  int onDelete (std::shared_ptr<ProjectionPlane> plane, std::shared_ptr<TwoDEntity> object);
public:
    int onCreate (std::shared_ptr<TwoDLine> object);
    IGUILineObserver (Canvas* _canvas) {canvas=_canvas;}
        ~IGUILineObserver();
};

class IGUIPlaneObserver {
  //  int onCreate (std::shared_ptr<ProjectionPlane> plane, std::shared_ptr<TwoDEntity> object);
  //B  int onChange (std::shared_ptr<ProjectionPlane> plane, std::shared_ptr<TwoDEntity> oldObject, std::shared_ptr<TwoDEntity> newObject);
  //  int onDelete (std::shared_ptr<ProjectionPlane> plane, std::shared_ptr<TwoDEntity> object);
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
