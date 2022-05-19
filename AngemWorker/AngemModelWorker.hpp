#ifndef ANGEM_MODEL_WORKER_H
#define ANGEM_MODEL_WORKER_H

#include "Angem.hpp"
#include "Entity.hpp"
#include "render.h"

class AngemModelWorker {
public:
    AngemModelWorker(PTR<Polyset<Entity>> container, PTR<Render> render) : container(container), render(render){}
    virtual ~AngemModelWorker();
    PTR<Entity> AddToModel(PTR<Entity> p); // добавить существующий объект в модель
    virtual PTR<Entity> AddToModelNew(Polyset<Entity> contP) = 0; // добавить новый объект в модель
    virtual void DeleteEntity(PTR<Entity> p); // удалить элемент
    virtual void DeleteRecurs(PTR<Entity> p);
    //virtual PTR<Entity> CreateEntity(Polyset<Entity> contP) = 0;
protected:
    PTR<Polyset<Entity>> container;
    PTR<Render> render;
};

//class LineWorker: public AngemModelWorker {
//public:
//    LineWorker(const LineWorker&) = delete;
//    LineWorker& operator=(const LineWorker&) = delete;
//    LineWorker(LineWorker&&) = delete;
//    LineWorker& operator=(LineWorker&&) = delete;
//
//    explicit LineWorker(PTR<Render> render, PTR<Polyset<Entity>> container);
//
//    ~LineWorker();
//    PTR<Entity> AddToModel(PTR<Entity> PLine);
//    PTR<Entity> AddToModelNew(Polyset<Entity> contP);
//
//    int DeleteEntity(PTR<Entity> PLine) { return 0; }
//    int DeleteRecurs(PTR<Entity> PLine) { return 0; }
//    PTR<Entity> CreateEntity(Polyset<Entity> contP) { return PTR<Line>(); }
//    //LineWorker init(PTR<Polyset<Entity>> cont){
//    //    return LineWorker();
//    //}
//};
//
//class PlaneWorker: AngemModelWorker {
//public:
//    ~PlaneWorker();
//    PTR<Entity> AddToModel(PTR<Entity> PPlane){ return PTR<Plane>(); }
//    PTR<Entity> AddToModelNew(Polyset<Entity> contP) { return PTR<Plane>(); }
//    int DeleteEntity(PTR<Entity> PPlane) { return 0; }
//    int DeleteRecurs(PTR<Entity> PPlane) { return 0; }
//    PTR<Entity> CreateEntity(Polyset<Entity> contP) { return PTR<Plane>(); }
//    PlaneWorker();
//    //PlaneWorker init(){
//    //    return PlaneWorker();
//    //}
//private:
//    static int counter;
//    PTR<Polyset<Entity>> container; 
//    PTR<Render> render;
//};
//
//class PointWorker: AngemModelWorker {
//public:
//    ~PointWorker();
//    PTR<Entity> AddToModel(PTR<Entity> PPoint){ return PTR<Point>(); }
//    PTR<Entity> AddToModelNew(Polyset<Entity> contP) { return PTR<Point>(); }
//    int DeleteEntity(PTR<Entity> PPoint) { return 0; }
//    int DeleteRecurs(PTR<Entity> PPoint) { return 0; }
//    PTR<Entity> CreateEntity(Polyset<Entity> contP) { return PTR<Point>(); }
//    PointWorker();
//    // PointWorker init(){
//    //     return PointWorker();
//    // }
//private:
//    PTR<Polyset<Entity>> container;
//    PTR<Render> render;
//};

#endif
