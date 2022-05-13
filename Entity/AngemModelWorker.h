//
// Created by Марат Гасанов on 12.05.2022.
//

#ifndef EDUCAD_ANGEMMODELWORKER_H
#define EDUCAD_ANGEMMODELWORKER_H

#include "Entity.hpp"
#include "Angem.hpp"

class AngemModelWorker {
public:
    virtual ~AngemModelWorker();
    virtual PTR<Entity> AddToModel(PTR<Entity> p) = 0; // добавить существующий объект в модель
    virtual PTR<Entity> AddToModelNew(Polyset<Entity> contP) = 0; // добавить новый объект в модель
    virtual int DeleteEntity(PTR<Entity> p) = 0; // удалить элемент
    virtual int DeleteRecurs(PTR<Entity> p) = 0;
    virtual PTR<Entity> CreateEntity(Polyset<Entity> contP) = 0;
private:
    PTR<Polyset<Entity> > container;
};

class LineWorker: AngemModelWorker {
public:
    ~LineWorker();
    PTR<Entity> AddToModel(PTR<Entity> PLine){ return PTR<Line>(); }
    PTR<Entity> AddToModelNew(Polyset<Entity> contP) { return PTR<Line>(); }
    int DeleteEntity(PTR<Entity> PLine) { return 0; }
    int DeleteRecurs(PTR<Entity> PLine) { return 0; }
    PTR<Entity> CreateEntity(Polyset<Entity> contP) { return PTR<Line>(); }
    LineWorker init(PTR<Polyset<Entity> > cont){
        return LineWorker();
    }
private:
    PTR<Polyset<Entity> > container;
    LineWorker();
};

class PlaneWorker: AngemModelWorker {
public:
    ~PlaneWorker();
    PTR<Entity> AddToModel(PTR<Entity> PPlane){ return PTR<Plane>(); }
    PTR<Entity> AddToModelNew(Polyset<Entity> contP) { return PTR<Plane>(); }
    int DeleteEntity(PTR<Entity> PPlane) { return 0; }
    int DeleteRecurs(PTR<Entity> PPlane) { return 0; }
    PTR<Entity> CreateEntity(Polyset<Entity> contP) { return PTR<Plane>(); }
    PlaneWorker init(){
        return PlaneWorker();
    }
private:
    PTR<Polyset<Entity> > container;
    PlaneWorker();
};

class PointWorker: AngemModelWorker {
public:
    ~PointWorker();
    PTR<Entity> AddToModel(PTR<Entity> PPoint){ return PTR<Point>(); }
    PTR<Entity> AddToModelNew(Polyset<Entity> contP) { return PTR<Point>(); }
    int DeleteEntity(PTR<Entity> PPoint) { return 0; }
    int DeleteRecurs(PTR<Entity> PPoint) { return 0; }
    PTR<Entity> CreateEntity(Polyset<Entity> contP) { return PTR<Point>(); }
    PointWorker init(){
        return PointWorker();
    }
private:
    PTR<Polyset<Entity> > container;
    PointWorker();
};

#endif //EDUCAD_ANGEMMODELWORKER_H
